#include <stdio.h>
#include "array_printer.h"


void print_net_point(TwoDimensionalIntNetPoint point) {

	printf("(%d, %.16f)", point.x, point.y);
}

void print_net_point_array_to_console(TwoDimensionalIntNetPoint* points, int length) {

		int i;

	for (i=0; i<length; i++) {
		print_net_point(points[i]);
		printf("\n");
	}
}
