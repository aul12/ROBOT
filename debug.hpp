/**
 * @file debug.hpp
 * @author Paul Nykiel, Tim Luchterhand
 * @brief Small file to handle all debug output in a flexible manner
 */

#ifndef ORANGEBALL_DEBUG_HPP
#define ORANGEBALL_DEBUG_HPP

#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/types.hpp>
#include <iostream>
#include <fstream>

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

    Output _output = NONE;
    std::ofstream debugFile;


    /**
     * Initialize the library and select the output.
     * @param output The output the library should write to.
     */
    void init(Output output){
        _output = output;
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
    void print(cv::String text){
        switch(_output){
            case STDOUT:
                std::cout << text;
                break;
            case FILE:
                debugFile << text;
                break;
            case NONE:break;
        }
    }

    /**
     * Print an integer to the selected output. After writing out the text the function will write a new line.
     * @param n the signed integer which should be printed
     */
    void printLn(int n){
        print(format("%d\n", n));
    }

    /**
     * Print a double to the selected output. After writing out the text the function will write a new line.
     * @param d the signed double which should be printed
     */
    void printLn(double d){
        print(format("%f\n", d));
    }

    /**
     * Print text to the selected output. After writing out the text the function will write a new line.
     * @param text the text which should be printed
     */
    void printLn(cv::String text){
        print(text+"\n");
    }

    /**
     * Print a point to the selected output. After writing out the text the function will write a new line.
     * The Text is formatted as ([X]|[Y]) with [X] and [Y] being the respective values of the point
     * @param p The point which should be displayed
     */
    void printLn(cv::Point p){
        print(format("(%d|%d)\n", p.x, p.y));
    }

    /**
     * Generate a new line on the selected output.
     */
    void printLn(){
        print("\n");
    }
}

#endif //ORANGEBALL_DEBUG_HPP
