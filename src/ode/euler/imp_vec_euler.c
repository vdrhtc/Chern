#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../../aux.h"
#include "../../output/array_printer.h"
#include "../../equation_solving/vec_solve.h"

VecMathFuncPointer2D equation_right_side;
Vector2D prevX;
double time_step;

Vector2D system_vec_func(Vector2D X) {
	return sub(mul(sub(X, prevX), 1/time_step), equation_right_side(X));
}

Vector2D imp_vec_euler_solution(Vector2D lastX, VecMathFuncPointer2D f) {
	equation_right_side = f;
	prevX = lastX;
//	Vector2D testX; testX.x1 = 10; testX.x2=-1+1e-9;
//	printf("%.16f\n", system_vec_func(testX).x2);
	return vec_newton_solve(&system_vec_func, lastX);
}

ParametricPoint2D* imp_vec_euler_solve(double t1, double t2, int steps,
		VecMathFuncPointer2D F) {

		double t = 0;
		Vector2D lastX; lastX.x1 = 2; lastX.x2 = 1;
		ParametricPoint2D* answer = calloc(steps, sizeof(ParametricPoint2D));
		double step = time_step = (t2 - t1) / steps;
		int i = 0;

	answer[i].X = lastX;
	answer[i].t = t;

	while (t < t2 - step) {
		i++;t+=step;

//		if(t>7.96)
		printf("%f\n" ,t);
		lastX = imp_vec_euler_solution(lastX, F);
		answer[i].X = lastX;
		answer[i].t = t;

	}
	return answer;
}
