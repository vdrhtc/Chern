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
	double x;

} TwoDimensionalNetPoint;

typedef void (*PointPrinter)(TwoDimensionalNetPoint);

void print_net_point_to_console(TwoDimensionalNetPoint);
void print_net_point_array_to_console(TwoDimensionalNetPoint*, int);
void print_net_point_array_to_file(TwoDimensionalNetPoint*, int, char *);





#endif /* ARRAY_PRINTER_H_ */
