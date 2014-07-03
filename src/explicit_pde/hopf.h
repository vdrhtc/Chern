/*
 * hopf.h
 *
 *  Created on: 12 июня 2014 г.
 *      Author: gleb
 */

#ifndef HOPF_H_
#define HOPF_H_


TimeLayer2D* solve_hopf(MathFuncPointer u_0_t, MathFuncPointer u_1_t, MathFuncPointer u_x_0,
		double a, double b, double t0, double t1, double h_x, double tau, double write_interval);


#endif /* HOPF_H_ */
