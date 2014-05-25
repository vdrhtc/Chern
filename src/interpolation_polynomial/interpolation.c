#include<stdio.h>
#include<math.h>
#include "../main.h"
#include "interpolation.h"
#include <stdlib.h>

double partial_polynomial_in(double x, int point_index, double* points,
		int degree) {

	double value = 1;
	int i;

	for (i = 0; i < degree+1; i++) {
		if (i != point_index) {
			value *= (x - points[i]);
		}
//		printf("Value partial = %f\n", value);
	}
	return value;
}

double lagrange_polynomial(double x, MathFuncPointer f, int degree,
		double* points) {

		int i;
		double value=0;

	for (i = 0; i < degree+1; i++) {
		double new  = f(points[i]) * partial_polynomial_in(x, i, points, degree)
						/ partial_polynomial_in(points[i], i, points, degree);
		value += new;

//		printf("Value full = %f\n", value);
	}

	return value;
}

