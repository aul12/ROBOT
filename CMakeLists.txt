cmake_minimum_required(VERSION 3.6)
project(OrangeBall)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ColourBased.hpp Canny.hpp HoughCircle.hpp CurvedLine.cpp CurvedLine.hpp CircleFinder.hpp Line.cpp Line.hpp CircleFinderResult.cpp CircleFinderResult.hpp)
add_executable(OrangeBall ${SOURCE_FILES})
target_link_libraries( OrangeBall ${OpenCV_LIBS}  -lpthread)