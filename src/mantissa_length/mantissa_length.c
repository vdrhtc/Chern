/*
 * mantissa_length.c
 *
 *  Created on: 24 апр. 2014 г.
 *      Author: gleb
 */

#include<math.h>
#include<stdio.h>
//#include "mantissa_length.h"

double double_get_degree_of_half(int degree) {
	return pow(2, -degree);
}

float float_get_degree_of_half(int degree) {
	return (float)pow(2, -degree);
}

int calculate_mantissa_length() {
	int degree_of_half;
	for (degree_of_half=0; degree_of_half<60; degree_of_half++) {
		double k = 1+double_get_degree_of_half(degree_of_half);
		printf("k %.16f ", (double)k);
		double l = 1 + double_get_degree_of_half(degree_of_half)/2.0;
		printf("l %.16f \n", (double)l);
		if (k!=1 && l==1) {
			printf("e = %e, mantissa = %d, sign = 1, degree_of_half = %d\n",
					double_get_degree_of_half(degree_of_half),
					degree_of_half, 64-degree_of_half-1);
			break;
		}

	}

	for (degree_of_half=0; degree_of_half<60; degree_of_half++) {
		float k = 1+float_get_degree_of_half(degree_of_half);
		printf("k %.7f ", k);
		float l = 1 + float_get_degree_of_half(degree_of_half)/2.0;
		printf("l %.7f \n", l);
		if (k!=1 && l==1) {
			printf("e = %e, mantissa = %d, sign = 1, degree_of_half = %d",
					float_get_degree_of_half(degree_of_half),
					degree_of_half, 32-degree_of_half-1);
			break;
		}

	}
	return 0;
}
