/*
 * proper_integration_analyzer.h
 *
 *  Created on: 25 апр. 2014 г.
 *      Author: gleb
 */

#include "../output/array_printer.h"

#ifndef PROPER_INTEGRATION_ANALYZER_H_
#define PROPER_INTEGRATION_ANALYZER_H_


Point2D * get_I_traps_against_N(int, MathFuncPointer, double a, double b);
Point2D * get_I_simps_against_N(int, MathFuncPointer, double a, double b);


#endif /* PROPER_INTEGRATION_ANALYZER_H_ */
