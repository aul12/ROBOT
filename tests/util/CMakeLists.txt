cmake_minimum_required(VERSION 3.6)
project(GenerateContours)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES generateConturs.cpp)
add_executable(GenerateContours ${SOURCE_FILES})
target_link_libraries( GenerateContours ${OpenCV_LIBS}  -lpthread)

