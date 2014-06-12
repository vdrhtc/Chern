#include <stdio.h>
#include "array_printer.h"
#include<stdlib.h>

Point2D* zip(double * X, double *Y, int minLen) {
		int i;
		Point2D* A = calloc(minLen, sizeof(Point2D));

	for (i = 0; i < minLen; i++) {
		Point2D a;
		a.x1 = X[i];
		a.x2 = Y[i];
		A[i] = a;
	}
	return A;
}

void print_point_to_console(Point2D point) {

	printf("(%f, %.16f)", point.x1, point.x2);
}

void print_point_array_to_console(Point2D* points, int length) {

		int i;

	for (i = 0; i < length; i++) {
		print_point_to_console(points[i]);
		printf(", ");
	}
}

void print_point_to_file(Point2D point, FILE *fp) {

	fprintf(fp, "(%f, %.16f)", point.x1, point.x2);
}

void print_point_array_to_file(Point2D* points, int length,
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

void print_parametric_point_to_file(ParametricPoint2D point,
		FILE *fp) {

	fprintf(fp, "(%f ,(%.16f, %.16f))", point.t, point.X.x1, point.X.x2);
}

void print_parametric_point_array_to_file(ParametricPoint2D* points,
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

void print_point_array_to_file_pointer(Point2D* points, int length,
		FILE* fp) {

		int i;

	fprintf(fp, "[");
	for (i = 0; i < length; i++) {
		if (i != 0)
			fprintf(fp, ", ");
		print_point_to_file(points[i], fp);

	}

	fprintf(fp, "]");
}

void print_TimeLayer2D_array_to_file(TimeLayer2D* TLs, int length_t, int length_x, char* filename) {

		int n;
		FILE* fp = fopen(filename, "w");

	fprintf(fp, "{");
	for(n=0; n<length_t; n++) {
		fprintf(fp, "%f:", TLs[n].t);
		print_point_array_to_file_pointer(TLs[n].layer2D, length_x, fp);
		fprintf(fp, ",\n");
	}
	fprintf(fp, "}");


}
