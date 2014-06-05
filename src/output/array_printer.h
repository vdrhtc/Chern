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
	double x2;
	double x1;

} Point2D;

typedef struct {
	double t;
	Vector2D X;
} ParametricPoint2D;

typedef void (*PointPrinter)(Point2D);

void print_point_to_console(Point2D);
void print_point_array_to_console(Point2D*, int);
void print_point_array_to_file(Point2D*, int, char *);
void print_parametric_point_array_to_file(ParametricPoint2D* ,
		int , char * );
Point2D* zip(double *, double *, int);




#endif /* ARRAY_PRINTER_H_ */
