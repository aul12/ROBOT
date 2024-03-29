cmake_minimum_required(VERSION 2.7)
project(OrangeBall)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp
        Filter/ColourBased.hpp
        Filter/Canny.hpp
        Filter/CircleFinder.hpp
        Filter/lib/Line.cpp
        Filter/lib/Line.hpp
        Filter/lib/CircleFinderResult.cpp
        Filter/lib/CircleFinderResult.hpp
        debug.hpp
        Profiler.hpp
        Profiler.cpp
        Serial.cpp
        Serial.hpp
        capture.hpp
        Filter/fusion.hpp
)
add_executable(OrangeBall ${SOURCE_FILES})
target_link_libraries( OrangeBall ${OpenCV_LIBS}  -lpthread)

#if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
#    find_package(Doxygen)
#    if(DOXYGEN_FOUND)
#        add_custom_target(DoxygenBuild COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_SOURCE_DIR}/doxygen.config"
#                WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY} COMMENT "Building user's documentation into doxyDoc build dir...")
#    endif(DOXYGEN_FOUND)
#
#    add_subdirectory(tests)
#endif()
