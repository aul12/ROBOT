cmake_minimum_required(VERSION 3.6)

project(Test)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(runUnitTests gtest.cpp ${test_SRCS})

target_link_libraries(runUnitTests ${GTEST_LIBS} -lgtest -lpthread)

add_test(
        NAME runUnitTests
        COMMAND runUnitTests
)