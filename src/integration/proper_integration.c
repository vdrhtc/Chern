#include<stdio.h>
#include<math.h>
#include "proper_integration.h"
#include "../aux.h"


double simps_integrate(int N, MathFuncPointer f, int silent, double a, double b) {

	if (N % 2 != 0) {
		printf("N should be even for this method");
		return 0;
	}

		double h = (b - a) / N;
		int n;

	double I = 0;
	for (n = 0; n < N - 1; n += 2) {
		I += (f(a + h * n) + 4. * f(a + (n + 1) * h)
				+ f(a + (n + 2) * h)) * h / 3.;
	}
	if(!silent)
		printf("I_simps = %.16f\n", I);
	return I;
}

double traps_integrate(int N, MathFuncPointer f, int silent, double a, double b) {

		double h = (b - a) / N;
		int n;

	double I = 0;
	for (n = 0; n < N; n++) {
		I += 0.5 * (f(a + h * n) + f(a + (n + 1) * h)) * h;
	}
	if (!silent)
		printf("I_traps = %.16f\n", I);
	return I;
}

double simps_integrate_double_density(int N, MathFuncPointer f, int silent, double a, double b) {

		double h = (b - a) / N;
		int n;

	double I = 0;
	for (n = 0; n < N ; n += 1) {
		I += (f(a + h * n) + 4. * f(a + (n + 0.5) * h)
				+ f(a + (n + 1) * h)) * h / 6.;
	}
	if(!silent)
		printf("I_simps = %.16f\n", I);
	return I;
}

void other_traps_integration(int N, MathFuncPointer f, double a, double b) {

		double h = (b - a) / N;
		int n;

	double I = h * (0.5 * f(a) + 0.5 * f(b));
	for (n = 1; n < N; n++) {
		I += h * f(a + h * n);
	}

	printf("I= %.16f\n", I);
}
