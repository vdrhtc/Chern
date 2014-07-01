/*
 * heatL1D.h
 *
 *  Created on: 30 июня 2014 г.
 *      Author: gleb
 */

#ifndef HEATL1D_H_
#define HEATL1D_H_

TimeLayer3D* locally_1D_solve_in_square(double _L, MathFuncPointer _f_x_0, MathFuncPointer _f_x_1, MathFuncPointer _f_y_0,
		MathFuncPointer _f_y_1, MathFuncPointer2D _u_0, double h_x, double h_y, double tau, double t, double write_interval);

#endif /* HEATL1D_H_ */
