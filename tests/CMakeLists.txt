cmake_minimum_required(VERSION 3.6)

project(Test)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

set(SOURCE_FILES ../ColourBased.hpp ../Canny.hpp ../CircleFinder.hpp ../Line.cpp ../Line.hpp ../CircleFinderResult.cpp ../CircleFinderResult.hpp)

add_executable(runUnitTests gtest.cpp ${test_SRCS} ${SOURCE_FILES})

target_link_libraries(runUnitTests ${GTEST_LIBS} -lgtest -lpthread)

add_test(
        NAME runUnitTests
        COMMAND runUnitTests
)