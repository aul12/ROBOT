//
// Created by paul on 06.06.17.
//

#ifndef ORANGEBALL_SERIAL_HPP
#define ORANGEBALL_SERIAL_HPP

#include <stdio.h>      // standard input / output functions
#include <iostream>
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions

namespace serial {
    void init();
    int sendChar(char data);
};


#endif //ORANGEBALL_SERIAL_HPP
