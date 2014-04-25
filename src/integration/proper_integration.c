#include<stdio.h>
#include<math.h>
#include "proper_integration.h"
#include "../main.h"

double lower_lim = -1, upper_lim = 1;

double simps_integrate(int N, MathFuncPointer f, int silent) {

	if (N % 2 != 0) {
		printf("N should be even for this method");
		return 0;
	}

		double h = (upper_lim - lower_lim) / N;
		int n;

	double I = 0;
	for (n = 0; n < N - 1; n += 2) {
		I += (f(lower_lim + h * n) + 4. * f(lower_lim + (n + 1) * h)
				+ f(lower_lim + (n + 2) * h)) * h / 3.;
	}
	if(!silent)
		printf("I_simps = %.16f\n", I);
	return I;
}

double traps_integrate(int N, MathFuncPointer f, int silent) {

		double h = (upper_lim - lower_lim) / N;
		int n;

	double I = 0;
	for (n = 0; n < N; n++) {
		I += 0.5 * (f(lower_lim + h * n) + f(lower_lim + (n + 1) * h)) * h;
	}
	if (!silent)
		printf("I_traps = %.16f\n", I);
	return I;
}

double simps_integrate_double_density(int N, MathFuncPointer f, int silent) {

		double h = (upper_lim - lower_lim) / N;
		int n;

	double I = 0;
	for (n = 0; n < N ; n += 1) {
		I += (f(lower_lim + h * n) + 4. * f(lower_lim + (n + 0.5) * h)
				+ f(lower_lim + (n + 1) * h)) * h / 6.;
	}
	if(!silent)
		printf("I_simps = %.16f\n", I);
	return I;
}

void other_traps_integration(int N, MathFuncPointer f) {

		double h = (upper_lim - lower_lim) / N;
		int n;

	double I = h * (0.5 * f(lower_lim) + 0.5 * f(upper_lim));
	for (n = 1; n < N; n++) {
		I += h * f(lower_lim + h * n);
	}

	printf("I= %.16f\n", I);
}
