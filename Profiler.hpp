/**
 * @file Profiler.hpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief Class and Wrapper to measure execution time of methods
 */

#ifndef ORANGEBALL_PROFILER_HPP
#define ORANGEBALL_PROFILER_HPP

#include <string>
#include <chrono>
#include <iostream>

#define PROF_ENABLED true 

/**
 * Start a profiler at this point with a certain name, this will manage everything.
 */
#define PROF_START(name) static Profiler name##Profiler(#name, PROF_ENABLED); name##Profiler.start();

/**
 * Stop a profiler with a certain name and print the results.
 */
#define PROF_END(name) name##Profiler.end();

/**
 * The profiler class is used to measure the average execution time of a certain part of the code.
 * @class Profiler
 * @brief Profile a certain part of the code
 */
class Profiler {
public:
    Profiler(std::string processName, bool enabled);
    void start();
    int end();
private:
    std::string processName;
    std::chrono::milliseconds startTime;
    double timeConsumed = 0;
    double runs = 0;
    bool enabled = true;
};

#endif //ORANGEBALL_PROFILER_HPP
