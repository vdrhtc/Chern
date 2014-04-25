#include<stdio.h>
#include<math.h>


double lower_lim = -1, upper_lim = 1;

static double f(double x) {
	return 1/(1+pow(x,2));
//	return x+1;
}

void simps_integrate(int N) {

		double h = (upper_lim - lower_lim)/N;
		int n;

	double I = 0;
	for (n = 0; n < N; n++) {
		I += (f(lower_lim+h*n)+4.*f(lower_lim+(n+1./2.)*h) + f(lower_lim+(n+1)*h))*h/6.;
	}

	printf("I_simps = %.16f\n", I);
}

void traps_integrate(int N) {

		double h = (upper_lim - lower_lim)/N;
		int n;

	double I = 0;
	for (n = 0; n < N; n++) {
		I += 0.5*(f(lower_lim+h*n)+f(lower_lim+(n+1)*h))*h;
	}

	printf("I_traps = %.16f\n", I);
}

void other_traps_integration(int N) {

		double h = (upper_lim - lower_lim)/N;
		int n;

	double I = h*(0.5*f(lower_lim)+0.5*f(upper_lim));
	for (n = 1; n < N; n++) {
		I += h*f(lower_lim+h*n);
	}

	printf("I= %.16f\n", I);
}
