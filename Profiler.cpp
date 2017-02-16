//
// Created by paul on 16.02.17.
//

#include "Profiler.hpp"
Profiler::Profiler(std::string processName) {
    this->processName = processName;
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
    std::chrono::duration<double> elapsed_seconds = now-startTime;

    this->timeConsumed = elapsed_seconds.count() * 1000;

    std::cout << processName << ": " << timeConsumed << "ms" << std::endl;
}
