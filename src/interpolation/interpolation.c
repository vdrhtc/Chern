#include<stdio.h>
#include<math.h>
#include "main.h"



double finite_difference_n(MathFuncPointer f, double* points, int degree) {

		int i, j;
		double* holder;
		double function_values[degree];

	for(i=0; i<degree; i++) {
		function_values[i] = points[i];
	}

	holder = function_values;

	for (i = 0; i<degree; i++) {
		double a[(degree-i-1)] = {0};

		for (j=0; j<(degree-i); j++) {
			a[j] = holder[j+1] - holder[j];
		}

		holder = a;
	}
	return holder[0];
}


double newton_polynomial(MathFuncPointer f, int degree, double* points) {
	printf("%f", finite_difference_n(f, points, degree));
	return 0;
}
