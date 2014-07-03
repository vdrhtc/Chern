#include <stdio.h>
#include "array_printer.h"
#include<stdlib.h>
#include <errno.h>
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

void print_point_array_to_file_pointer(Point2D* points, int length, FILE* fp) {
		int i;

	fprintf(fp, "[");
		for (i = 0; i < length; i++) {
			if (i != 0)
				fprintf(fp, ", ");
			print_point_to_file(points[i], fp);

		}
	fprintf(fp, "]");
}

void print_point_array_to_file(Point2D* points, int length,
		char * filename) {

		FILE* fp = fopen(filename, "w");
		print_point_array_to_file_pointer(points, length, fp);
}

void print_tuple_of_point_arrays_to_file(Point2DArray* points, int amount,
		char * filename) {

		int i;
		FILE* fp = fopen(filename, "w");

	fprintf(fp, "(");
	for(i=0; i<amount; i++) {
		print_point_array_to_file_pointer(points[i].points, points[i].length, fp);
		fprintf(fp, ",\n ");
	}
	fprintf(fp, ")");
}

void print_parametric_point_to_file(ParametricPoint2D point,
		FILE *fp) {

	fprintf(fp, "(%f ,(%.16f, %.16f))", point.t, point.X.x1, point.X.x2);
}

void print_parametric_point_array_to_file(ParametricPoint2D* points,
		int length, char * filename) {

		int i;
		FILE* fp = fopen(filename, "w");
		if(fp==NULL)
			printf("%d", errno);

	fprintf(fp, "[");
	for (i = 0; i < length; i++) {
		if (i != 0)
			fprintf(fp, ", ");
		print_parametric_point_to_file(points[i], fp);

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

void print_TimeLayer3D_array_to_file(TimeLayer3D* TLs, int length_t, char* filename) {
		int n, n_x, n_y;
		FILE* fp = fopen(filename, "w");

	fprintf(fp, "({");
	for (n=0; n<length_t; n++) {
		fprintf(fp, "%f:", TLs[n].t);
		fprintf(fp, "array([");
		for(n_y=0; n_y<TLs[n].layer3D.steps_y; n_y++) {
			fprintf(fp, "[");
			for (n_x=0; n_x<TLs[n].layer3D.steps_x; n_x++) {
				fprintf(fp, "%f, ", TLs[n].layer3D.values[n_x][n_y]);
			}
			fprintf(fp, "], ");
		}
		fprintf(fp, "]), ");

	}
	fprintf(fp, "},\n ");

	fprintf(fp, "array([");
	for (n_x=0; n_x<TLs[0].layer3D.steps_x; n_x++) {
		fprintf(fp, "%f, ", TLs[0].layer3D.x_0+n_x*TLs[0].layer3D.h_x);
	}
	fprintf(fp, "]),\n ");

	fprintf(fp, "array([");
	for (n_y=0; n_y<TLs[0].layer3D.steps_x; n_y++) {
		fprintf(fp, "%f, ", TLs[0].layer3D.y_0+n_y*TLs[0].layer3D.h_y);
	}
	fprintf(fp, "]) )");

}
