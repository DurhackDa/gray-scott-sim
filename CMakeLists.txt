cmake_minimum_required(VERSION 3.0.0)
project(googletest VERSION 0.1.0 LANGUAGES C CXX)

include(GoogleTest)
include(CTest)
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
add_executable(
  test
  test.cpp
)

target_link_libraries(
  test
  gs
  GTest::gtest_main
)
include(GoogleTest)
# gtest_discover_tests(gs)