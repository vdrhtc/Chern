#include "../../aux.h"
#include "../../output/array_printer.h"
#include <stdlib.h>

Vector vec_runge_kutta_solution(double time_step, Vector lastV, VecMathFuncPointer2D f) {
	Vector k1 = f(sum(lastV, mul(f(lastV), 1./2.*time_step)));
	return sum(lastV, mul(k1, (time_step)));
}



ParametricPoint2D* vec_runge_kutta_solve(double t1, double t2,
		int steps, VecMathFuncPointer2D f, Vector U_0) {

		double t = t1;
		Vector lastU; lastU.x1 = U_0.x1; lastU.x2 = U_0.x2;
		ParametricPoint2D* answer = calloc(steps, sizeof(ParametricPoint2D));
		double step = (t2 - t1) / steps;
		int i = 0;

	answer[i].X = lastU;
	answer[i].t = t;

	while (t < t2 - step) {
		i++;t+=step;

		lastU = vec_runge_kutta_solution(step, lastU, f);
		answer[i].X = lastU;
		answer[i].t = t;

	}
	return answer;
}
