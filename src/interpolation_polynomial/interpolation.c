#include<stdio.h>
#include<math.h>
#include "../aux.h"
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

Point2D* interpolate(MathFuncPointer f, int degree, double* points, double a, double b, int steps) {

		Point2D* data = calloc(steps, sizeof(Point2D));
		double step = 3.14*4/16/steps;
		double x=0;
		int i=0;

	while(x<3.14*4/16) {
		Point2D XY;
		XY.x1 = x;
		XY.x2 = lagrange_polynomial(x, f, 4, points);
		data[i] = XY;
		x+=step;
		i++;
	}
	return data;

}

