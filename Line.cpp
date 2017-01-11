/**
 * @file Line.cpp
 * @author Paul Nykiel, Tim Luchterhand
 */
#include <cmath>
#include "Line.hpp"

/**
 * Constructor: define a Line through two points
 * @param p1 the first point the line should go through
 * @param p2 the second point the line should go through
 */
Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

/**
 * Constructor: define a Line through a point and a gradient
 * @param p the point the line should go through
 * @param m the gradient of the line
 */
Line::Line(Point p, double m) {
    this->p1 = p;
    this->p2 = Point(p.x + 128, p.y + (int)(m*128));
}

/**
 * Get the line in 90deg angle to the Line
 * @param p the point the line should go through
 * @return a new Line which intersects the Line in the given point
 */
Line Line::getInverted(Point p) {
    if(isVertical()){
        return Line(p, Point(p.x + 1, p.y));
    }else if(isHorizontal()){
        return Line(p, Point(p.x, p.y + 1));
    }else{//reziprognegative Steigung berechnen
        return Line(p, -1/getGradient());
    }
}

/**
 * Check if a line is Vertical (Parallel to the x-Axis)
 * @return a boolean which is true when the line is vertical
 */
bool Line::isVertical() {
    return p1.x == p2.x;
}

/**
 * Check if a line is Horizontal (Parallel to the y-Axis)
 * @return a boolean which is true when the line is horizontal
 */
bool Line::isHorizontal() {
    return p1.y == p2.y;
}

/**
 * Get the current gradient of the line (dx/dy)
 * @return the gradient of the line, return -1 if the line is vertical
 * @throw returns -1 if line is vertical (gradient is actually infinity)
 * @see isVertical
 */
double Line::getGradient() {
    if(isVertical())
        return -1;
    else
        return (p2.y-p1.y)/(double)(p1.x-p2.x);
}

/**
 * Get the intersection of the current line with the given line, always check existsIntersection before!
 * @see existsIntersection
 * @param line the current line should check the intersection with
 * @return the point both lines are intersecting
 */
Point Line::getIntersection(Line line) {
    if(this->isVertical()){
        return Point(this->p1.x, line.getY(this->p1.x));
    }else if(line.isVertical()){
        return Point(line.p1.x, this->getY(line.p1.x));
    }else{
        int x = (int)((this->getC() - line.getC())/(line.getGradient() - this->getGradient()));
        return Point(x, this->getY(x));
    }
}

/**
 * Get the y value of the line at a certain x position
 * @param x the x value the y value should be calculated
 * @return the y value of the line, or -1 if the line is vertical
 * @throw -1 if line is vertical and there is no well-defined y-Value, please check isVertical beforehand
 * @see isVertical
 */
int Line::getY(int x) {
    if(this->isVertical())
        return -1;
    else
        return (int)(this->p1.y + (x - this->p1.x) * getGradient());
}

/**
 * Get the Y value at x=0
 * @return the y value of the line at x=0
 */
int Line::getC() {
    return getY(0);
}

/**
 * Check if an intersection between two lines exists
 * @param line the second line
 * @return a boolean which is true if there is a well-defined intersection
 */
bool Line::existsIntersection(Line line) {
    return !((this->isVertical() && line.isVertical()) || this->getGradient() == line.getGradient());
}

/**
 * Get the distance of the two points which define the line (similar to a normal abs function of a line with limited length)
 * @return the distance of both points which were used to define the line
 */
int Line::getDistPoints() {
    return (int)sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
