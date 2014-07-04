#include<stdio.h>
#include<math.h>
#include "solve.h"

double h = 2e-16;

static double f(double x) {
	return x - 1.0 + (12.0) / (exp(2 / x) + 9);
}

static double f_newton(double x) {
	return x - 1/((f(x+h)-f(x-h))/2/h) * f(x);
}

static double f_iter(double x) {
	return x-.10*f(x);
}


void newton_solve(double x_0) {
	printf("Searching from %f\n", x_0);

			double x_prev = x_0;
			double x_next, x_last;
			int sanity_check_counter = 0;

		do {
			sanity_check_counter++;
			x_last = x_prev;
			x_next = f_newton(x_prev);
			x_prev = x_next;
		} while(fabs(x_last-x_next) > 2e-17 && sanity_check_counter < 10000);

		if(sanity_check_counter >= 10000)
		{
			printf("Method does not converge\n");
			return;
		}
		printf("Approximate solution (precision to machine epsilon): %.16f\n", x_next);
}

void iter_solve(double x_0) {

	printf("Searching from %f\n", x_0);

		double x_prev = x_0;
		double x_next, x_last;
		int sanity_check_counter = 0;

	do {
		sanity_check_counter++;
		x_last = x_prev;
		x_next = f_iter(x_prev);
		x_prev = x_next;
	} while(fabs(x_last-x_next) > 2e-17 && sanity_check_counter < 10000);

	if(sanity_check_counter >= 10000)
	{
		printf("Method does not converge\n");
		return;
	}
	printf("Approximate solution (precision to machine epsilon): %.16f\n", x_next);
}


void bisec_solve(double xmin, double xmax) {


	if (f(xmin) * f(xmax) > 0) {
		printf("There is possibly no solution in (%f, %f) , try other interval\n",
				xmin, xmax);
		return;
	}

	printf("Searching in (%f, %f)...\n",
					xmin, xmax);

	double middle = (xmax + xmin) / 2.0;
	double last_middle = 0;

	do {
		last_middle = middle;

		if ((f(middle) * f(xmax)) > 0) {
			xmax = middle;
			middle = (xmin + middle) / 2;
		} else {
			xmin = middle;
			middle = (middle + xmax) / 2;
		}


	} while (fabs(middle - last_middle) > 2e-17);


	printf("Approximate solution (precision to machine epsilon): %.16f\n", middle);
}
