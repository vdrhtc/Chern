#include <stdio.h>
#include "array_printer.h"
#include<stdlib.h>

TwoDimensionalNetPoint* zip(double * X, double *Y, int minLen) {
		int i;
		TwoDimensionalNetPoint* A = calloc(minLen, sizeof(TwoDimensionalNetPoint));

	for (i = 0; i<minLen; i++) {
		TwoDimensionalNetPoint a;
		a.x = X[i];
		a.y = Y[i];
		A[i] = a;
	}
	return A;
}



void print_point_to_console(TwoDimensionalNetPoint point) {

	printf("(%f, %.16f)", point.x, point.y);
}

void print_point_array_to_console(TwoDimensionalNetPoint* points, int length) {

		int i;

	for (i=0; i<length; i++) {
		print_point_to_console(points[i]);
		printf(", ");
	}
}

void print_point_to_file(TwoDimensionalNetPoint point, FILE *fp) {

	fprintf(fp, "(%f, %.16f)", point.x, point.y);
}

void print_point_array_to_file(TwoDimensionalNetPoint* points, int length, char * filename) {

		int i;
		FILE* fp = fopen(filename, "w");


		fprintf(fp, "[");
	for (i=0; i<length; i++) {
		if(i!=0)
			fprintf(fp, ", ");
		print_point_to_file(points[i], fp);

	}

	fprintf(fp, "]");
}
