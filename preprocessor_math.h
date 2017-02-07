//
// Created by paul on 07.02.17.
//

#ifndef ORANGEBALL_PREPROCESSOR_MATH_H_H
#define ORANGEBALL_PREPROCESSOR_MATH_H_H

#define PI 3.14159265358979
#define E EXP(1)

#define SQ(x) ((x)*(x))
#define COS(x) (1 - 1/2.0 * SQ(x) + 1/24.0 * SQ(SQ(x)))
#define SIN(x) (COS(X) - PI/2)
#define TAN(X) (SIN(X)/COS(X))
#define COT(x) (COS(X)/SIN(X))
#define EXP(x) (1+(x)+SQ(x)/2.0 + (x)*SQ(x)/6.0 + SQ(SQ(x))/24.0)


#define DEG_TO_RAD(x) ((x)/57.3)
#define RAD_TO_DEG(x) ((x)*57.3)

#endif //ORANGEBALL_PREPROCESSOR_MATH_H_H
