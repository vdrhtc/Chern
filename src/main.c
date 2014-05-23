/*
 * main.c
 *
 *  Created on: 24 апр. 2014 г.
 *      Author: gleb
 */

#include "mantissa_length/mantissa_length.h"
#include "series_summarizing/summarizer.h"
#include "equation_solving/solve.h"
#include "integration/proper_integration.h"
#include "integration/proper_integration_analyzer.h"
#include "output/array_printer.h"
#include <stdio.h>
#include <math.h>


double f1(double x) {
	return 1/(pow(x, 2) + 1);
}

double f2(double x) {
	return (cos(x)-1)/pow(x, 1./3.);
}

double f3(double x) {
	return (1+exp(-x))/(1+pow(x,(3./2.)));
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



	return 0;
}
