#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include "proper_integration.h"
#include "../output/array_printer.h"
#include "../main.h"

TwoDimensionalNetPoint * get_I_traps_against_N(int N_interval, MathFuncPointer f, double a, double b) {

		TwoDimensionalNetPoint * I_traps_against_N = calloc(2*N_interval, sizeof(TwoDimensionalNetPoint));
		int N;

	for (N=1; N<N_interval; N++) {
		TwoDimensionalNetPoint point;

		point.x = N;
		point.y = traps_integrate(N, f, 1, a, b);

		*(I_traps_against_N+N-1) = point;
	}


	return I_traps_against_N;
}

TwoDimensionalNetPoint * get_I_simps_against_N(int N_interval, MathFuncPointer f, double a, double b) {

		TwoDimensionalNetPoint * I_simps_against_N = calloc(N_interval, sizeof(TwoDimensionalNetPoint));
		int N;

	for (N=1; N<N_interval; N++) {

		TwoDimensionalNetPoint point;

		point.x = N;
		point.y = simps_integrate_double_density(N, f, 1, a, b);

		*(I_simps_against_N+N-1) = point;
		}
	return I_simps_against_N;
}
