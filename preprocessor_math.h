/**
 * @file preprocessor_math.h
 * @authors Paul Nykiel, Tim Luchterhand
 * @brief Collection of small algorithm to calculate computation-heavy things at compile-time
 */

#ifndef ORANGEBALL_PREPROCESSOR_MATH_H_H
#define ORANGEBALL_PREPROCESSOR_MATH_H_H

#define PI 3.14159265358979 ///<Definition of the constant PI
#define E EXP(1)            ///<Definition of the euler-constant as the value of exp(1)

#define SQ(x) ((x)*(x)) ///<Macro to square the argument
#define COS(x) (1 - 1/2.0 * SQ(x) + 1/24.0 * SQ(SQ(x))) ///<Value of the cosine function, approximation using a taylor series
#define SIN(x) (COS(X) - PI/2)  ///<Calculate the sine as a shifted cosine
#define TAN(X) (SIN(X)/COS(X))  ///<Calculate the tangent-function
#define COT(x) (COS(X)/SIN(X))  ///<Calculate the cotangent-function
#define EXP(x) (1+(x)+SQ(x)/2.0 + (x)*SQ(x)/6.0 + SQ(SQ(x))/24.0)   ///<Value of the exponential function, approximation using a taylor series

#define DEG_TO_RAD(x) ((x)/57.3)  ///<Convert the argument from degrees to radians
#define RAD_TO_DEG(x) ((x)*57.3)  ///<Convert the argument from radians to degrees

#endif ORANGEBALL_PREPROCESSOR_MATH_H_H