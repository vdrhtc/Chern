/*
 * array_printer.h
 *
 *  Created on: 25 апр. 2014 г.
 *      Author: gleb
 */

#ifndef ARRAY_PRINTER_H_
#define ARRAY_PRINTER_H_


typedef struct {
	double y;
	int x;

} TwoDimensionalIntNetPoint;

typedef void (*PointPrinter)(TwoDimensionalIntNetPoint);

void print_net_point(TwoDimensionalIntNetPoint);
void print_net_point_array_to_console(TwoDimensionalIntNetPoint*, int);





#endif /* ARRAY_PRINTER_H_ */
