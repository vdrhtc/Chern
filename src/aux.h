/*
 * aux.h
 *
 *  Created on: 27 мая 2014 г.
 *      Author: gleb
 */

#ifndef AUX_H_
#define AUX_H_


typedef struct {
	double x;
	double y;
} Vector;

typedef Vector (*VecMathFuncPointer)(Vector);

Vector mul(Vector, double);
Vector sum(Vector, Vector);

#endif /* AUX_H_ */
