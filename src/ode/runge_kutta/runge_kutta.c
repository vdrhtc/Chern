#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../../aux.h"


double runge_kutta_solution(double t, double lastT, double lastX, MathFuncPointer f) {
	return lastX + (t-lastT)*f(lastX+1./2.*(t-lastT)*f(lastX));
}


double** runge_kutta_solve(double a, double b, int steps, MathFuncPointer f) {
	double t, lastX = 1, lastT = 0;
			double * Xs = calloc(steps, sizeof(double));
			double * Ts = calloc(steps, sizeof(double));
			double ** answer = calloc(2, sizeof(double*));
			double step = (b-a)/steps;
			int i = 0;

		Xs[i] = lastX;
		Ts[i] = lastT;
		while(t < b-step) {
			i++;
			t+=step;
			lastX = runge_kutta_solution(t, lastT, lastX, f);
			Xs[i] = lastX;
			lastT = t;
			Ts[i] = lastT;

		}
		answer[0] = Xs;
		answer[1] = Ts;
		return answer;
}
