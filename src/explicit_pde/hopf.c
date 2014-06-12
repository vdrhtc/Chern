#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../aux.h"

TimeLayer2D build_next_layer(MathFuncPointer u_0_t, TimeLayer2D* TLs, double a,
		int steps_x, double h_x, double t, double tau, int layer_number) {

		int m;
		TimeLayer2D nextTL;
		nextTL.t = t;
		nextTL.layer2D = calloc(steps_x, sizeof(Point2D));

	nextTL.layer2D[0].x1 = a;
	nextTL.layer2D[0].x2 = u_0_t(t);

	for(m=1; m<steps_x; m++) {
		nextTL.layer2D[m].x1 = a+m*h_x;
		double u_m = TLs[layer_number-1].layer2D[m].x2;
		double u_m_1 = TLs[layer_number-1].layer2D[m-1].x2;
		nextTL.layer2D[m].x2 = u_m - tau/h_x/2*(u_m*u_m - u_m_1*u_m_1);
	}

	return nextTL;

}

TimeLayer2D build_first_layer(MathFuncPointer u_x_0, double a, int steps_x, double h_x) {

		int m;
		TimeLayer2D TL;

	TL.t = 0;
	TL.layer2D = calloc(steps_x, sizeof(Point2D));
	for(m=0; m<steps_x; m++) {
		TL.layer2D[m].x1 = a+m*h_x;
		TL.layer2D[m].x2 = u_x_0(a+m*h_x);

	}
	return TL;
}

TimeLayer2D* solve_hopf(MathFuncPointer u_0_t, MathFuncPointer u_x_0,
		double a, double b, double t0, double t1, double h_x, double tau) {

		int steps_t = (t1-t0)/tau, n;
		TimeLayer2D* TLs = calloc(steps_t, sizeof(TimeLayer2D));
		int steps_x = (b-a)/h_x;

	TLs[0] = build_first_layer(u_x_0, a, steps_x, h_x);

	for(n=1; n<steps_t; n++) {
		TLs[n] = build_next_layer(u_0_t, TLs, a, steps_x, h_x, n*tau,tau, n);
	}
	return TLs;

}
