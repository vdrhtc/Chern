/*
 * main.c
 *
 *  Created on: 24 апр. 2014 г.
 *      Author: gleb
 */

#include "mantissa_length/mantissa_length.h"
#include "series_summarizing/summarizer.h"
#include "equation_solving/solve.h"
#include "integration/proper_integration.h"
#include "integration/proper_integration_analyzer.h"
#include "output/array_printer.h"
#include <stdio.h>
#include <math.h>


double f1(double x) {
	return 1/(pow(x, 2) + 1);
}


int main() {
//	calculate_mantissa_length();

//	summarize();

//	bisec_solve(-1, 1);

//	iter_solve(-1);

//	newton_solve(-0.1);

	traps_integrate(16, &f1, 0);

	simps_integrate(16, &f1, 0);

	print_net_point_array_to_console(get_I_simps_against_N(10170, &f1), 10169);

	return 0;
}
