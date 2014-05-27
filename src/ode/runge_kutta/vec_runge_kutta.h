/*
 * vec_runge_kutta.h
 *
 *  Created on: 27 мая 2014 г.
 *      Author: gleb
 */

#ifndef VEC_RUNGE_KUTTA_H_
#define VEC_RUNGE_KUTTA_H_

TwoDimensionalParametricPoint* vec_runge_kutta_solve(double, double, int,
		VecMathFuncPointer);

#endif /* VEC_RUNGE_KUTTA_H_ */
