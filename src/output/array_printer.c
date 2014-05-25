#include <stdio.h>
#include "array_printer.h"


void print_net_point_to_console(TwoDimensionalNetPoint point) {

	printf("(%f, %.16f)", point.x, point.y);
}

void print_net_point_array_to_console(TwoDimensionalNetPoint* points, int length) {

		int i;

	for (i=0; i<length; i++) {
		print_net_point_to_console(points[i]);
		printf(", ");
	}
}

void print_net_point_to_file(TwoDimensionalNetPoint point, FILE *fp) {

	fprintf(fp, "(%f, %.16f)", point.x, point.y);
}

void print_net_point_array_to_file(TwoDimensionalNetPoint* points, int length, char * filename) {

		int i;
		FILE* fp = fopen(filename, "w");


		fprintf(fp, "[");
	for (i=0; i<length; i++) {
		print_net_point_to_file(points[i], fp);
		fprintf(fp, ", ");
	}

	fprintf(fp, "]");
}
