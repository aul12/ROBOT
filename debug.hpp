/**
 * @file debug.hpp
 * @author Paul Nykiel, Tim Luchterhand
 * @brief Small library to handle all debug output in a flexible manner
 */

#ifndef ORANGEBALL_DEBUG_HPP
#define ORANGEBALL_DEBUG_HPP

#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/types.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>


/**
 * @brief Namespace used for writing debug output to a specified output (stdout, file...)
 */
namespace dbg{

    /**
     * Enum containing all options where the debug information is written to
     */
    enum Output{
        NONE,   ///<Do not write the debug output anywhere. The output does not get buffered!
        STDOUT, ///<Write the debug output into the stdout (usually the console)
        FILE    ///<Write the debug output into a file called log.txt. The file is located in the same directory as the binary
    };

    /**
     * Enum containing all Log-Levels. When one log level is selected all smaller log levels are displayed
     * as well, order is: LOG < WARN < ERROR
     */
    enum LogLevel{
        LOG,    ///<Most common log level, log all necessary data
        WARN,   ///<Small warning, reasons for algorithms to fail etc.
        ERROR   ///<Severe issues, issues regarding i/o etc.
    };

    Output _output = NONE;
    LogLevel _logLevel = LOG;
    std::ofstream debugFile;

    /**
     * Initialize the library and select the output.
     * @param output The output the library should write to.
     */
    void init(Output output, LogLevel logLevel){
        _output = output;
        _logLevel = logLevel;
        switch (output){
            case FILE:
                debugFile.open("log.txt", std::ios::trunc);
                break;
            case NONE:break;
            case STDOUT:break;
        }

    }

    /**
     * Always call this function before exiting the program.
     * Otherwise your output won't be written to the debug file
     */
    void close(){
        switch(_output){
            case NONE:break;
            case STDOUT:break;
            case FILE:
                debugFile.close();
                break;
        }
    }

    /**
     * Prototype function which implements printing a simple string to the selected output.
     * @param text The text to be printed
     * @see Output
     */
    void print(cv::String text, LogLevel level = LOG){
        if(level >= _logLevel){
            //std::time_t timeNow = std::time(nullptr);
            switch(_output){
                case STDOUT:
                    std::cout /*<< std::put_time(std::localtime(&timeNow), "%OH:%OM:%OS") << ":\t" */<< text;
                    break;
                case FILE:
                    debugFile /*<< std::put_time(std::localtime(&timeNow), "%OH:%OM:%OS") << ":\t"*/ << text;
                    break;
                case NONE:break;
            }
        }
    }


    /**
     * Print text to the selected output. After writing out the text the function will write a new line.
     * The string output gets prepended by a timestamp formatted as (HOUR:MINUTE:SECOND).
     * @param text the text which should be printed
     * @see Output
     */
    void println(cv::String text, LogLevel level = LOG){
        print(text + "\n", level);
    }

    /**
     * Generate a new line on the selected output.
     */
    void println(LogLevel level = LOG){
        print("\n", level);
    }

    /**
     * Print an integer to the selected output. After writing out the text the function will write a new line.
     * @param n the signed integer which should be printed
     */
    void println(int n, LogLevel level = LOG){
        println(format("%d", n), level);
    }

    /**
     * Print a double to the selected output. After writing out the text the function will write a new line.
     * @param d the signed double which should be printed
     */
    void println(double d, LogLevel level = LOG){
        println(format("%f", d), level);
    }

    /**
     * Print a point to the selected output. After writing out the text the function will write a new line.
     * The Text is formatted as ([X]|[Y]) with [X] and [Y] being the respective values of the point
     * @param p The point which should be displayed
     */
    void println(cv::Point p, LogLevel level = LOG){
        println(format("(%d|%d)", p.x, p.y), level);
    }

    /**
    * Print an integer to the selected output.
    * @param n the signed integer which should be printed
    */
    void print(int n, LogLevel level = LOG){
        print(format("%d", n), level);
    }

    /**
     * Print a double to the selected output.
     * @param d the signed double which should be printed
     */
    void print(double d, LogLevel level = LOG){
        print(format("%f", d), level);
    }

    /**
     * Print a point to the selected output.
     * The Text is formatted as ([X]|[Y]) with [X] and [Y] being the respective values of the point
     * @param p The point which should be displayed
     */
    void print(cv::Point p, LogLevel level = LOG){
        print(format("(%d|%d)", p.x, p.y), level);
    }
}

#endif //ORANGEBALL_DEBUG_HPP
