#include "gtest/gtest.h"
#include "gs.hpp"  // 替换为你的模拟文件头文件

// 测试模拟步骤函数
TEST(GrayScottSimulation, SimulationStep) {
    // 创建 GrayScottSimulation 对象
    GrayScottSimulation simulation;

    // 调用初始化函数
    simulation.init();

    // 备份模拟数组的初始状态
    std::vector<std::vector<double>> initialU = simulation.getU();
    std::vector<std::vector<double>> initialV = simulation.getV();

    // 执行一步模拟
    simulation.simulateStep();

    // 获取模拟数组的最新状态
    std::vector<std::vector<double>> updatedU = simulation.getU();
    std::vector<std::vector<double>> updatedV = simulation.getV();

    // 在这里编写断言，检查模拟步骤是否符合预期
    // 例如，可以检查数组中的值是否在合理的范围内
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            EXPECT_GE(updatedU[x][y], 0.0);
            EXPECT_LE(updatedU[x][y], 1.0);
            EXPECT_GE(updatedV[x][y], 0.0);
            EXPECT_LE(updatedV[x][y], 1.0);
        }
    }
    
    // 还可以检查模拟后的数组是否与初始状态有所不同
    EXPECT_NE(updatedU, initialU);
    EXPECT_NE(updatedV, initialV);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}