/*
 * proper_integration.h
 *
 *  Created on: 24 апр. 2014 г.
 *      Author: gleb
 */

#include "../main.h"

#ifndef PROPER_INTEGRATION_H_
#define PROPER_INTEGRATION_H_

double traps_integrate(int N, MathFuncPointer f, int silent, double a, double b);
double simps_integrate(int N, MathFuncPointer f, int silent, double a, double b);
void other_traps_integration(int N, MathFuncPointer f, double a, double b);
double simps_integrate_double_density(int N, MathFuncPointer f, int silent, double a, double b);

#endif /* PROPER_INTEGRATION_H_ */
