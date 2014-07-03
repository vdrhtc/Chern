/*
 * imp_vec_euler.h
 *
 *  Created on: 05 июня 2014 г.
 *      Author: gleb
 */

#ifndef IMP_VEC_EULER_H_
#define IMP_VEC_EULER_H_

ParametricPoint2D* imp_vec_euler_solve(double t1, double t2, int steps,
		VecMathFuncPointer2D F, Vector U_0);

#endif /* IMP_VEC_EULER_H_ */
