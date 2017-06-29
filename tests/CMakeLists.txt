cmake_minimum_required(VERSION 3.5)

project(Test)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ../Filter/ColourBased.hpp ../Filter/Canny.hpp ../Filter/CircleFinder.hpp ../Filter/lib/Line.cpp ../Filter/lib/Line.hpp ../Filter/lib/CircleFinderResult.cpp ../Filter/lib/CircleFinderResult.hpp ../Profiler.cpp ../Profiler.hpp)
add_executable(RunUnitTests gtest.cpp ${test_SRCS} ${SOURCE_FILES})

target_link_libraries(RunUnitTests ${GTEST_LIBS} ${OpenCV_LIBS} -lgtest -lpthread)

add_test(
        NAME RunUnitTests
        COMMAND RunUnitTests
)

add_subdirectory(util)