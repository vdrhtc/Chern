#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include "proper_integration.h"
#include "../output/array_printer.h"
#include "../aux.h"

Point2D * get_I_traps_against_N(int N_interval, MathFuncPointer f, double a, double b) {

		Point2D * I_traps_against_N = calloc(2*N_interval, sizeof(Point2D));
		int N;

	for (N=1; N<N_interval; N++) {
		Point2D point;

		point.x1 = N;
		point.x2 = traps_integrate(N, f, 1, a, b);

		*(I_traps_against_N+N-1) = point;
	}


	return I_traps_against_N;
}

Point2D * get_I_simps_against_N(int N_interval, MathFuncPointer f, double a, double b) {

		Point2D * I_simps_against_N = calloc(N_interval, sizeof(Point2D));
		int N;

	for (N=1; N<N_interval; N++) {

		Point2D point;

		point.x1 = N;
		point.x2 = simps_integrate_double_density(N, f, 1, a, b);

		*(I_simps_against_N+N-1) = point;
		}
	return I_simps_against_N;
}
