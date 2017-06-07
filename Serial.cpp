//
// Created by paul on 06.06.17.
//

#include "Serial.hpp"

namespace serial {
    int usb = 0;

    void init() {
        /* Open File Descriptor */
        usb = open("/dev/ttyUSB0", O_RDWR | O_NONBLOCK | O_NDELAY);

        /* Error Handling */
        if (usb < 0) {
           std:: cout << "Error " << errno << " opening " << "/dev/ttyUSB0" << ": " << strerror(errno) << std::endl;
        }

        /* *** Configure Port *** */
        struct termios tty;
        memset(&tty, 0, sizeof tty);

        /* Error Handling */
        if (tcgetattr(usb, &tty) != 0) {
            std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
        }

        /* Set Baud Rate */
        cfsetospeed(&tty, B38400);
        cfsetispeed(&tty, B38400);

        /* Setting other Port Stuff */
        tty.c_cflag &= ~PARENB;        // Make 8n1
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8;
        tty.c_cflag &= ~CRTSCTS;       // no flow control
        tty.c_lflag = 0;          // no signaling chars, no echo, no canonical processing
        tty.c_oflag = 0;                  // no remapping, no delays
        tty.c_cc[VMIN] = 0;                  // read doesn't block
        tty.c_cc[VTIME] = 5;                  // 0.5 seconds read timeout

        tty.c_cflag |= CREAD | CLOCAL;     // turn on READ & ignore ctrl lines
        tty.c_iflag &= ~(IXON | IXOFF | IXANY);// turn off s/w flow ctrl
        tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
        tty.c_oflag &= ~OPOST;              // make raw

        /* Flush Port, then applies attributes */
        tcflush(usb, TCIFLUSH);

        if (tcsetattr(usb, TCSANOW, &tty) != 0) {
            std::cout << "Error " << errno << " from tcsetattr" << std::endl;
        }

    }

    int sendChar(char data) {
        char buffer[] = {data};
        return (int) write(usb, buffer, 1);
    }
}