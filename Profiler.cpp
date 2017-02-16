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
    this->startTime = std::chrono::duration_cast<std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
}

int Profiler::end() {
    std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
    std::chrono::duration<double> elapsedSeconds = now-startTime;

    double timeThisRun = elapsedSeconds.count() * 1000;
    this->timeConsumed += timeThisRun;
    runs++;

    std::cout << processName << ": " << (timeConsumed/runs) << "ms" << std::endl;

    return (int) timeThisRun;
}
