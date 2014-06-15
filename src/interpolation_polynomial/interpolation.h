/*
 * interpolation.h
 *
 *  Created on: 25 мая 2014 г.
 *      Author: gleb
 */

#ifndef INTERPOLATION_H_
#define INTERPOLATION_H_

double lagrange_polynomial(double, MathFuncPointer, int, double*);
Point2D* interpolate(MathFuncPointer f, int degree, double* points, double a, double b, int steps);
#endif /* INTERPOLATION_H_ */
