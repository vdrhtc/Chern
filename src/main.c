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
#include "pde/heatL1D.h"
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
	return (2*exp(1-1/x/x)+2)/(pow(x,3)+pow(-x*x+1, 3./2.));
}

double f4(double x) {
	return cos(x);
}

double f5(double x) {
	return -x-pow(x, 2);
}

Vector F1(Vector point) {
	Vector Y;
	Y.x1 = 10*point.x1-2*point.x1*point.x2;
	Y.x2 = 2*point.x1*point.x2 - 10*point.x2;
	return Y;
}
Vector F2(Vector point) {
	Vector Y;
	Y.x1 = point.x1*10-pow(point.x2,2)+1;
	Y.x2 = point.x1+point.x2;
	return Y;
}

Vector F3(Vector point) {
	Vector F;
	F.x1 = 998*point.x1+1998*point.x2;
	F.x2 = -999*point.x1-1999*point.x2;
	return F;
}

LinearSystem fillTridiagonalMatrixAndOrdinal(MathFuncPointer rightPart, double h, double a, double b) {

		int steps = round((b-a)/h)+1;
		int i, dimension=steps;
		SquareMatrix M = getSquareMatrix(dimension);
		NDVector V = getNDVector(dimension);

	V.data[0] = 0;
	for (i=1; i<dimension-1; i++) {
		V.data[i] = h*h*rightPart(a+i*h);
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
	return 0;
}

double u_1_t(double t) {
	return 0;
}

double modified_sin(double x) {
	return pow(sin(50*x), 1)+sin(x*30.5)+sin(128*x);
}


double f_x(double x) {
	return 1-pow(x,2);
}

double f_y(double y) {
	return 1-y*y;
}

double f_x_other(double x) {
	return -f_x(x);
}

double u_i(double x, double y) {
	return 0;
}

int main() {

	/*
	 * Задача 1
	 */

//	calculate_mantissa_length();

	/*
	 * Задача 2
	 */

//	summarize();

	/*
	 * Задача 3
	 */

//	bisec_solve(-.1, .1);
//
//	iter_solve(-0);
//
//	newton_solve(0.1);

	/*
	 * Задача 4
	 */
//	traps_integrate(16000000, &f1, 0, -1, 1);
//	simps_integrate(16000, &f1, 0, -1, 1);
//	print_point_array_to_file(get_I_traps_against_N(101,&f1,-1, 1), 100,"./src/integration/traps.txt");
//	print_point_array_to_file(get_I_simps_against_N(202,&f1,-1, 1), 100,"./src/integration/simps.txt");
//	traps_integrate(200, exp, 0, 0, 5);

	/*
	 * Задача 5
	 */
//	double I_2 = simps_integrate(10000, &f2, 1, 0.00000000001, 1);
//	printf("I_simps = I_1 + I_2 = 2*3/2*x^(2/3)|0, 1 + I= 3 %f = %.16f", I_2, 3+I_2);

	/*
	 * Задача 6
	 */


//	simps_integrate(10000, &f3, 0, 0,1);
	/*
	 * Задача 7
	 */

//		double points[] = {0 ,3.14*1/16, 3.14*2/16, 3.14*3/16, 3.14*4/16};
//		int steps = 100;
////
//	Point2D* data = interpolate(&cos,4, points, -.5, 1.2, steps);
////
//	print_point_array_to_file(data, steps, "./src/interpolation_polynomial/interpolation_data.txt");

	/*
	 * Задача 8
	 */
//
//	Point2D* answer_euler = euler_solve(0, 3, 50, &f5);
//	print_point_array_to_file(answer_euler, 50, "./src/ode/euler/euler.txt");
//	Point2D* answer_kutta = runge_kutta_solve(0, 3, 50, &f5);
//	print_point_array_to_file(answer_kutta, 50, "./src/ode/runge_kutta/runge_kutta.txt");
//		int i, N=300, k=0;
//		Point2DArray* functions = calloc(N, sizeof(Point2D*));
//	for(i=10; i<=N; i+=10) {
//		functions[i/10-1].points = runge_kutta_solve(0, 3, i, &f5);
//		functions[i/10-1].length = i;
//		k++;
//	}
//
//	print_tuple_of_point_arrays_to_file(functions, k,  "./src/ode/runge_kutta/kuttas.txt");

	/*
	 * Задача 9
	 */
//	Vector U_0; U_0.x1 = 2; U_0.x2 = 1;
//	ParametricPoint2D* a_vec_kutta = vec_runge_kutta_solve(0, 3, 220, &F1, U_0);
//	print_parametric_point_array_to_file(a_vec_kutta, 100, "./src/ode/runge_kutta/prey.txt");


	/*
	 * Задача 10
	 */

//	int steps = 1e4; Vector U_0;
//	U_0.x1=2; U_0.x2=1;
//	ParametricPoint2D* a_imp_vec_euler = imp_vec_euler_solve(0, .01, steps, &F3, U_0);
//	print_parametric_point_array_to_file(a_imp_vec_euler, steps, "./src/ode/euler/hard_border.txt");
//	a_imp_vec_euler = imp_vec_euler_solve(0.01, 1, steps/100, &F3, a_imp_vec_euler[steps].X);
//	print_parametric_point_array_to_file(a_imp_vec_euler, steps/100, "./src/ode/euler/hard_slow.txt");
//
//	ParametricPoint2D* a_vec_kutta = vec_runge_kutta_solve(0, .01, steps, &F3, U_0);
//	print_parametric_point_array_to_file(a_vec_kutta, steps, "./src/ode/runge_kutta/hard_border.txt");
//	a_vec_kutta = vec_runge_kutta_solve(0.01, 1, steps/100, &F3, a_vec_kutta[steps].X);
//	print_parametric_point_array_to_file(a_vec_kutta, steps/100, "./src/ode/runge_kutta/hard_slow.txt");


	/*
	 *Задача 11
	 */
//
//	double a = 0, b = M_PI;
//	int i;
//	double h = M_PI/100;
//	int steps = round((b-a)/h)+1;
//
//	LinearSystem L = fillTridiagonalMatrixAndOrdinal(sin, h, a, b);
//	NDVector u_s = tridiagonal_solve(L.M, L.V);
//
//	double* x_s = calloc(steps, sizeof(double));
//	for(i=0; i<steps; i++)
//		x_s[i] = i*h;
//
//	printf("%.16f", x_s[steps-1]);
//	print_point_array_to_file(zip(x_s, u_s.data, u_s.dimension), u_s.dimension, "./src/linear_solving/sin.txt");


	/*
	 * Задача 12
	 */

//	double a = -5, b=10;
//	double t0 = 0, t1 = 2;
//	double h_x = 0.01, tau = 0.0001, write_interval=0.1;
//
//	TimeLayer2D* TLs = solve_hopf(&u_0_t, &u_1_t, &u_x_0, a, b, t0, t1, h_x, tau, write_interval);
//	print_TimeLayer2D_array_to_file(TLs, (t1-t0)/write_interval+1, (b-a)/h_x, "./src/explicit_pde/hopf.txt");

	/*
	 * Задача 13
	 */

	int N = 1024;
	double L = 2*M_PI;
	Point2D* sample = make_sample_rect_window(modified_sin, N, -L/2, L);
	Point2D* power_spectrum = spectral_power(sample, N, L);
	print_point_array_to_file(power_spectrum, N, "./src/dft/dft_rect.txt");

	sample = make_sample_hann_window(modified_sin, N, -L/2, L);
	power_spectrum = spectral_power(sample, N, L);
	print_point_array_to_file(power_spectrum, N, "./src/dft/dft_hann.txt");
	print_point_array_to_console(sample, N);


	/*
	 * Персональное задание
	 */
//	double t=1.5, tau= 0.01, wi = 0.1;
//	TimeLayer3D* layers = locally_1D_solve_in_square(1, &f_x, &f_x, &f_y, &f_y, &u_i, 0.1, 0.1, tau, t, wi);
//	print_TimeLayer3D_array_to_file(layers, t/wi+1,"./src/pde/heat.txt");

	return 0;
}
