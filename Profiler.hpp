//
// Created by paul on 16.02.17.
//

#ifndef ORANGEBALL_PROFILER_HPP
#define ORANGEBALL_PROFILER_HPP

#include <string>
#include <chrono>
#include <iostream>

#define PROF_START(name) static Profiler name##Profiler(#name, PROF_ENABLED); name##Profiler.start();
#define PROF_END(name) name##Profiler.end();

class Profiler {
public:
    Profiler(std::string processName);
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
