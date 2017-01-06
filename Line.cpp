//
// Created by paul on 05.01.17.
//

#include <cmath>
#include "Line.hpp"

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

Line::Line(Point p, double m) {
    this->p1 = p;
    //@TODO -> nicht schön!
    /*if(abs(m) > 1000)
        this->p2 = Point(p.x, p.y+1);
    else*/
        this->p2 = Point(p.x + 128, p.y + (int)(m*128));
}

Line Line::getInverted(Point p) {
    if(isVertical()){
        return Line(p, Point(p.x + 1, p.y));
    }else if(isHorizontal()){
        return Line(p, Point(p.x, p.y + 1));
    }else{//reziprognegative Steigung berechnen
        return Line(p, -1/getGradient());
    }
}

bool Line::isVertical() {
    return p1.x == p2.x;
}

bool Line::isHorizontal() {
    return p1.y == p2.y;
}

double Line::getGradient() {
    //@TODO nicht schön
    if(isVertical())
        return NAN;
    else
        return (p2.y-p1.y)/(double)(p1.x-p2.x);
}


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

int Line::getY(int x) {
    //@TODO potenzielle Fehlerquelle
    if(this->isVertical())
        return -1;
    else
        return (int)(this->p1.y + (x - this->p1.x) * getGradient());
}

int Line::getC() {
    return getY(0);
}

bool Line::existsIntersection(Line line) {
    //Kein wohldefinierter Schnittpunkt
    return !((this->isVertical() && line.isVertical()) || this->getGradient() == line.getGradient());
}

