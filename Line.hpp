//
// Created by paul on 05.01.17.
//

#ifndef ORANGEBALL_LINE_HPP
#define ORANGEBALL_LINE_HPP

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;

class Line {
    public:
        Line(Point p1, Point p2);
        Line(Point p, double m);
        Line getInverted(Point p);
        double getGradient();
        bool existsIntersection(Line line);
        Point getIntersection(Line line);
        int getY(int x);
        int getC();
        int getAngleDegree();
        int getDistPoints();
    private:
        Point p1, p2;
        bool isVertical();
        bool isHorizontal();
};


#endif //ORANGEBALL_LINE_HPP
