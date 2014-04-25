/*
 * proper_integration_analyzer.h
 *
 *  Created on: 25 апр. 2014 г.
 *      Author: gleb
 */

#include "../output/array_printer.h"

#ifndef PROPER_INTEGRATION_ANALYZER_H_
#define PROPER_INTEGRATION_ANALYZER_H_


TwoDimensionalIntNetPoint * get_I_traps_against_N(int, MathFuncPointer);
TwoDimensionalIntNetPoint * get_I_simps_against_N(int, MathFuncPointer);


#endif /* PROPER_INTEGRATION_ANALYZER_H_ */
