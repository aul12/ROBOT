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



/**
 * @brief Namespace used for writing debug output to a specified output (stdout, file...)
 */
namespace dbg{

    /**
     * Enum containing all options where the debug information is written to
     */
    enum Output{
        NONE,   ///<Do not write the debug output anywhere. The output does not get buffered!
        STDOUT  ///<Write the debug output into the stdout (usually the console)
    };

    Output _output = NONE;


    /**
     * Set the output to one of the options of the Enum Output.
     * @param output the output which should be used
     * @see Output
     */
    void setOutput(Output output){
        _output = output;
    }

    /**
     * Print text to the selected output
     * @param text the text which should be printed
     */
    void print(cv::String text){
        if(_output == STDOUT)
            std::cout << text << std::endl;
    }

    /**
     * Print a point to the selected output.
     * The Text is formatted as ([X]|[Y]) with [X] and [Y] being the respective values of the point
     * @param p The point which should be displayed
     */
    void print(cv::Point p){
        if(_output == STDOUT)
            std::cout << "(" << p.x << "|" << p.y << ")" << std::endl;
    }

    /**
     * Generate a new line on the selected output
     */
    void newLine(){
        if(_output == STDOUT)
            std::cout << std::endl;
    }
}

#endif //ORANGEBALL_DEBUG_HPP
