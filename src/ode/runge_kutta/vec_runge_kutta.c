#include "../../aux.h"
#include "../../output/array_printer.h"
#include <stdlib.h>

Vector2D vec_runge_kutta_solution(double time_step, Vector2D lastV, VecMathFuncPointer2D f) {
	Vector2D k1 = f(sum(lastV, mul(f(lastV), 1./2.*time_step)));
	return sum(lastV, mul(k1, (time_step)));
}



ParametricPoint2D* vec_runge_kutta_solve(double t1, double t2,
		int steps, VecMathFuncPointer2D f) {

		double t = 0;
		Vector2D lastU; lastU.x1 = 10; lastU.x2 = 1;
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
