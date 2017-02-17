//
// Created by paul on 16.02.17.
//
#include "Profiler.hpp"

Profiler::Profiler(std::string processName) {
    this->processName = processName;
    runs = 0;
    timeConsumed = 0;
}

void Profiler::start() {
    if(enabled){
        this->startTime = std::chrono::duration_cast<std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()
        );
    }
}

int Profiler::end() {
    if(enabled){
        std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()
        );
        std::chrono::duration<double> elapsedSeconds = now-startTime;

        double timeThisRun = elapsedSeconds.count() * 1000;
        this->timeConsumed += timeThisRun;
        runs++;

        std::cout << "\033[34m" <<processName << ": " << (timeConsumed/runs) << "ms \\033[0m\\n" << std::endl;

        return (int) timeThisRun;
    }
    return 0;
}

Profiler::Profiler(std::string processName, bool enabled) {
    this->enabled = enabled;
    this->processName = processName;
    runs = 0;
    timeConsumed = 0;
}
