#include "../../main.h"
#include "../../aux.h"
#include "../../output/array_printer.h"
#include <stdlib.h>

Vector vec_runge_kutta_solution(double t, double lastT, Vector lastV, VecMathFuncPointer f) {
	Vector k1 = f(sum(lastV, mul(f(lastV), 1./2.*(t-lastT))));
	return sum(lastV, mul(k1, (t-lastT)));
}



TwoDimensionalParametricPoint* vec_runge_kutta_solve(double a, double b,
		int steps, VecMathFuncPointer f) {

		double t, lastT = 0;
		Vector lastU; lastU.x = 10; lastU.y = 1;
		TwoDimensionalParametricPoint* answer = calloc(steps, sizeof(TwoDimensionalParametricPoint));
		double step = (b - a) / steps;
		int i = 0;

	answer[i].U = lastU;
	answer[i].t = lastT;

	while (t < b - step) {
		i++;
		t += step;
		lastU = vec_runge_kutta_solution(t, lastT, lastU, f);
		answer[i].U = lastU;
		lastT = t;
		answer[i].t = lastT;

	}
	return answer;
}
