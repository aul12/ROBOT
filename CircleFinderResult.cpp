/**
 * @file CircleFinderResult.cpp
 * @author Paul Nykiel, Tim Luchterhand
 */

#include "CircleFinderResult.hpp"

/**
 * Constructor to generate a new object with zero radius and a centre at (0,0).
 * This is usually used to generate a non-circle object.
 * @param isCircle
 * @see CircleFinderResult(Point centre, int radius, bool isCircle)
 */
CircleFinderResult::CircleFinderResult(bool isCircle) {
    this->isCircle = isCircle;
    this->radius = 0;
    this->centre = Point(0,0);
}

/**
 * Constructor to generate a new object with a defined radius and a defined centre.
 * This is usually used to generate a valid circle.
 * @param centre the centre of the circle
 * @param radius the radius of the circle
 * @param isCircle a boolean whether or not the object is a circle (if it is false you can call the other constructor)
 * @see CircleFinderResult(bool isCircle)
 */
CircleFinderResult::CircleFinderResult(Point centre, int radius, bool isCircle) {
    this->isCircle = isCircle;
    this->centre = centre;
    this->radius = radius;
}
