#include<stdio.h>
#include<math.h>


double lower_lim = -1, upper_lim = 1;

static double f(double x) {
	return 1/(1+pow(x,2));
}

void simps_integrate(int N) {

		double h = (upper_lim - lower_lim)/N;
		int n;

	double I = 0;
	for (n = 0; n < N-1; n++) {
		I += (f(lower_lim+h*n)+4.*f(lower_lim+(n+1./2.)*h) + f(lower_lim+(n+1)*h))*h/6.;
	}

	printf("I= %f\n", I);
}

void traps_integrate(int N) {

		double h = (upper_lim - lower_lim)/N;
		int n;

	double I = 0;
	for (n = 0; n < N-1; n++) {
		I += 0.5*(f(lower_lim+h*n)+f(lower_lim+(n+1)*h))*h;
	}

	printf("I= %f\n", I);
}
