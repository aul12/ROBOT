//
// Created by paul on 16.02.17.
//

#ifndef ORANGEBALL_PROFILER_HPP
#define ORANGEBALL_PROFILER_HPP

#include <string>
#include <chrono>
#include <iostream>


class Profiler {
    public:
        Profiler(std::string processName);
        void start();
        int end();
    private:
        std::string processName;
        std::chrono::milliseconds startTime;
        double timeConsumed = 0;
};


#endif //ORANGEBALL_PROFILER_HPP
