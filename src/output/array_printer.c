#include <stdio.h>
#include "array_printer.h"
#include<stdlib.h>

TwoDimensionalPoint* zip(double * X, double *Y, int minLen) {
		int i;
		TwoDimensionalPoint* A = calloc(minLen, sizeof(TwoDimensionalPoint));

	for (i = 0; i < minLen; i++) {
		TwoDimensionalPoint a;
		a.x = X[i];
		a.y = Y[i];
		A[i] = a;
	}
	return A;
}

void print_point_to_console(TwoDimensionalPoint point) {

	printf("(%f, %.16f)", point.x, point.y);
}

void print_point_array_to_console(TwoDimensionalPoint* points, int length) {

		int i;

	for (i = 0; i < length; i++) {
		print_point_to_console(points[i]);
		printf(", ");
	}
}

void print_point_to_file(TwoDimensionalPoint point, FILE *fp) {

	fprintf(fp, "(%f, %.16f)", point.x, point.y);
}

void print_point_array_to_file(TwoDimensionalPoint* points, int length,
		char * filename) {

		int i;
		FILE* fp = fopen(filename, "w");

	fprintf(fp, "[");
	for (i = 0; i < length; i++) {
		if (i != 0)
			fprintf(fp, ", ");
		print_point_to_file(points[i], fp);

	}

	fprintf(fp, "]");
}

void print_parametric_point_to_file(TwoDimensionalParametricPoint point,
		FILE *fp) {

	fprintf(fp, "(%f ,(%.16f, %.16f))", point.t, point.U.x, point.U.y);
}

void print_parametric_point_array_to_file(TwoDimensionalParametricPoint* points,
		int length, char * filename) {

		int i;
		FILE* fp = fopen(filename, "w");

	fprintf(fp, "[");
	for (i = 0; i < length; i++) {
		if (i != 0)
			fprintf(fp, ", ");
		print_parametric_point_to_file(points[i], fp);

	}

	fprintf(fp, "]");
}
