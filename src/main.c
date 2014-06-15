/*
 * main.c
 *
 *  Created on: 24 апр. 2014 г.
 *      Author: gleb
 */

#include "mantissa_length/mantissa_length.h"
#include "series_summarizing/summarizer.h"
#include "equation_solving/solve.h"
#include "equation_solving/vec_solve.h"
#include "integration/proper_integration.h"
#include "integration/proper_integration_analyzer.h"
#include "output/array_printer.h"
#include "interpolation_polynomial/interpolation.h"
#include "ode/euler/euler.h"
#include "ode/runge_kutta/runge_kutta.h"
#include "ode/runge_kutta/vec_runge_kutta.h"
#include "ode/euler/imp_vec_euler.h"
#include "output/matrix_printer.h"
#include "linear_solving/tridiagonal/tridiagonal_solving.h"
#include "explicit_pde/hopf.h"
#include "dft/dft.h"
#include "aux.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double f1(double x) {
	return 1/(pow(x, 2) + 1);
}

double f2(double x) {
	return (cos(x)-1)/pow(x, 1./3.);
}

double f3(double x) {
	return (1+exp(-x))/(1+pow(x,(3./2.)));
}

double f4(double x) {
	return cos(x);
}

double f5(double x) {
	return -x-pow(x, 2);
}

Vector2D F1(Vector2D point) {
	Vector2D Y;
	Y.x1 = 10*point.x1-2*point.x1*point.x2;
	Y.x2 = 2*point.x1*point.x2 - 10*point.x2;
	return Y;
}
Vector2D F2(Vector2D point) {
	Vector2D Y;
	Y.x1 = point.x1*10-pow(point.x2,2)+1;
	Y.x2 = point.x1+point.x2;
	return Y;
}

Vector2D F3(Vector2D point) {
	Vector2D F;
	F.x1 = 998*point.x1+1998*point.x2;
	F.x2 = -999*point.x1-1999*point.x2;
	return F;
}

LinearSystem fillTridiagonalMatrixAndOrdinal(MathFuncPointer rightPart, int steps, double a, double b) {

		int i, dimension = steps;
		SquareMatrix M = getSquareMatrix(dimension);
		NDVector V = getNDVector(dimension);
		double step = (b-a)/steps;

	V.data[0] = 0;
	for (i=1; i<dimension-1; i++) {
		V.data[i] = step*step*rightPart(a+i*step);
	}
	V.data[dimension-1] = 0;

	M.data[0][0] = 1;
	for (i=1; i<dimension-1; i++) {
		M.data[i][i-1] = 1;
		M.data[i][i] = -2;
		M.data[i][i+1] = 1;
	}
	M.data[dimension-1][dimension-1] = 1;
	LinearSystem L;
	L.M = M;
	L.V = V;
	return L;
}

double u_x_0(double x) {
	return exp(-pow(x,2)/2);
}


double u_0_t(double t) {
	return exp(-t-5*5/2);
}

double modified_sin(double x) {
	return pow(sin(50*x), 1)+sin(x*30.5);
}

int main() {
//	calculate_mantissa_length();

//	summarize();

//	bisec_solve(-1, 1);

//	iter_solve(-1);

//	newton_solve(-0.1);

//	traps_integrate(16, &f1, 0, -1, 1);

	/*
	 * Задача 5
	 */
//	double I_2 = simps_integrate(16, &f2, 1, 0.000001, 1);
//	printf("I_simps = I_1 + I_2 = 2*3/2*x^(2/3)|0, 1 + I= 3 %f = %.16f", I_2, 3+I_2);

	/*
	 * Задача 6
	 */
//	double b = 1e3;
//	double I_1 = simps_integrate(16*b, &f3, 1,  0, b);
//	double I_2 = 2./pow(b, 1./2.);
//	printf("I = I_1 + I_2 = %.10e + %.10e = %.16f", I_1, I_2, I_1+I_2);

	/*
	 * Задача 7
	 */

//		double a[] = {0 ,3.14*1/16, 3.14*2/16, 3.14*3/16, 3.14*4/16};
//		int steps = 100;
//		TwoDimensionalNetPoint* data = calloc(steps, sizeof(TwoDimensionalNetPoint));
//
//		double step = 3.14*4/16/steps;
//		double x;
//		int i=0;
//
//	while(x<3.14*4/16) {
//		TwoDimensionalNetPoint XY;
//		XY.x = x;
//		XY.y = lagrange_polynomial(x, &f4, 4, a);
//		data[i] = XY;
//		x+=step;
//		i++;
//	}
//	print_point_array_to_file(data, steps, "./src/interpolation_polynomial/interpolation_data.txt");

	/*
	 * Задача 8
	 */

//	TwoDimensionalPoint* answer_euler = euler_solve(0, 3, 50, &f5);
//	print_point_array_to_file(answer_euler, 50, "./src/ode/euler/euler.txt");
//	double ** answer_kutta = runge_kutta_solve(0, 3, 50, &f5);
//	print_point_array_to_file(zip(answer_kutta[1], answer_kutta[0], 50), 50, "./src/ode/runge_kutta/runge_kutta.txt");

	/*
	 * Задача 9
	 */
//	ParametricPoint2D* a = vec_runge_kutta_solve(0, 1, 10000, &F3);
//	print_parametric_point_array_to_file(a, 10000, "./src/ode/runge_kutta/prey.txt");


	/*
	 * Задача 10
	 */

//	int steps = 1e4;
//	ParametricPoint2D* a = imp_vec_euler_solve(0, 10, steps, &F3);
//	print_parametric_point_array_to_file(a, steps, "./src/ode/euler/hard.txt");

	/*
	 *Задача 11
	 */

//	double a = 0, b = 3.141529;
//	int i;
//	int steps = 100;
//
//	LinearSystem L = fillTridiagonalMatrixAndOrdinal(sin, steps, a, b);
//	NDVector u_s = tridiagonal_solve(L.M, L.V);
//
//	double* x_s = calloc(steps, sizeof(double));
//	for(i=0; i<steps; i++)
//		x_s[i] = i*(b-a)/steps;
//	print_point_array_to_file(zip(x_s, u_s.data, u_s.dimension), u_s.dimension, "./src/linear_solving/sin.txt");


	/*
	 * Задача 12
	 */

//	double a = -5, b=10;
//	double t0 = 0, t1 = 3;
//	double h_x = 0.01, tau = 0.01;
//
//	TimeLayer2D* TLs = solve_hopf(&u_0_t, &u_x_0, a, b, t0, t1, h_x, tau);
//	print_TimeLayer2D_array_to_file(TLs, (t1-t0)/tau, (b-a)/h_x, "./src/explicit_pde/hopf.txt");

	/*
	 * Задача 13
	 */
//
//	int N = 1024;
//	double L = 2*M_PI;
//	Point2D* sample = make_sample_rect_window(modified_sin, N, -L/2, L);
//	Point2D* power_spectrum = spectral_power(sample, N, L);
//	print_point_array_to_file(power_spectrum, N, "./src/dft/dft_rect.txt");
//
//	sample = make_sample_hann_window(modified_sin, N, -L/2, L);
//	power_spectrum = spectral_power(sample, N, L);
//	print_point_array_to_file(power_spectrum, N, "./src/dft/dft_hann.txt");
//	print_point_array_to_console(sample, N);

	return 0;
}
