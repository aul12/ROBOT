/**
 * @file Profiler.cpp
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief Implementation of Profiler.hpp
 */

#include "Profiler.hpp"

/**
 * Initialize the Profiler
 * @param processName The name the process should be listed as in the output
 * @param enabled enable or disable the profiler. The profiler will use nearly no ressources if disabled
 */
Profiler::Profiler(std::string processName, bool enabled) {
    this->enabled = enabled;
    this->processName = processName;
    runs = 0;
    timeConsumed = 0;
}

/**
 * Start the profiler, this is the start of the time measurement of the profiler. If the profiler is disabled nothing
 * will happen.
 */
void Profiler::start() {
    if(enabled){
        this->startTime = std::chrono::duration_cast<std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()
        );
    }
}

/**
 * End the profiler. If enabled the profiler will print the process name and the execution time onto the stdout.
 * @return the time in ms the process took this run.
 */
int Profiler::end() {
    if(enabled){
        std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()
        );
        std::chrono::duration<double> elapsedSeconds = now-startTime;

        double timeThisRun = elapsedSeconds.count() * 1000;
        this->timeConsumed += timeThisRun;
        runs++;

        std::cout << "\033[34m" <<processName << ": " << (timeConsumed/runs) << "ms\n" << std::endl;

        return (int) timeThisRun;
    }
    return 0;
}