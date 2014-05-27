/*
 * array_printer.h
 *
 *  Created on: 25 апр. 2014 г.
 *      Author: gleb
 */



#ifndef ARRAY_PRINTER_H_
#define ARRAY_PRINTER_H_
#include "../aux.h"

typedef struct {
	double y;
	double x;

} TwoDimensionalPoint;

typedef struct {
	double t;
	Vector U;
} TwoDimensionalParametricPoint;

typedef void (*PointPrinter)(TwoDimensionalPoint);

void print_point_to_console(TwoDimensionalPoint);
void print_point_array_to_console(TwoDimensionalPoint*, int);
void print_point_array_to_file(TwoDimensionalPoint*, int, char *);
void print_parametric_point_array_to_file(TwoDimensionalParametricPoint* ,
		int , char * );
TwoDimensionalPoint* zip(double *, double *, int);




#endif /* ARRAY_PRINTER_H_ */
