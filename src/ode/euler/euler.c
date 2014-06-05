#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../../output/array_printer.h"
#include "../../aux.h"


double euler_solution(double t, double lastT, double lastX, MathFuncPointer f) {
	return lastX+(t-lastT)*f(lastX);
}


Point2D* euler_solve(double a, double b, int steps, MathFuncPointer f) {

		double t, lastX = 1, lastT = 0;
		Point2D* points = calloc(steps, sizeof(Point2D));
		double step = (b-a)/steps;
		int i = 0;

	points[i].x1 = lastX;
	points[i].x2 = lastT;
	while(t < b-step) {
		i++;
		t+=step;
		lastX = euler_solution(t, lastT, lastX, f);
		points[i].x1 = lastX;
		lastT = t;
		points[i].x2 = lastT;

	}
	return points;
}
