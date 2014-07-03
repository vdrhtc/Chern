#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../aux.h"
#include "../linear_solving/tridiagonal/tridiagonal_solving.h"

int steps_x, steps_y;
double h_x, h_y, tau;
double L;
MathFuncPointer f_x_0, f_x_1, f_y_0, f_y_1;
MathFuncPointer2D u_0;

Layer3D build_border(Layer3D L) {
		int n_x, n_y;

	for (n_x = 0; n_x<steps_x; n_x++) {
		L.values[n_x][0] = f_x_0(L.x_0+L.h_x*n_x);
		L.values[n_x][steps_y-1] = f_x_1(L.x_0+L.h_x*n_x);
	}
	for(n_y = 0; n_y<steps_y; n_y++) {
		L.values[0][n_y] = f_y_0(L.y_0+L.h_y*n_y);
		L.values[steps_x-1][n_y] = f_y_1(L.y_0+L.h_y*n_y);
	}
	return L;
}

TimeLayer3D build_initial_layer() {

		TimeLayer3D TL;
		TL.t = 0;
		int n_x, n_y;
		TL.layer3D = init_layer3D(steps_x, steps_y, h_x, h_y, -L, -L);

	TL.layer3D = build_border(TL.layer3D);
	for (n_x=1; n_x<steps_x-1; n_x++)
		for(n_y=1; n_y<steps_y-1; n_y++) {
			TL.layer3D.values[n_x][n_y] = u_0(TL.layer3D.x_0+TL.layer3D.h_x*n_x,
					TL.layer3D.y_0+TL.layer3D.h_y*n_y);
		}
	return TL;

}


Layer3D build_y_stripe(Layer3D L, Layer3D pL, int n_y) {
		SquareMatrix M = getSquareMatrix(steps_x);
		NDVector O = getNDVector(steps_x);
		int i;

	O.data[0] = L.values[0][n_y];
	for(i=1; i<steps_x-1; i++) {
		O.data[i] = (2 - 2*h_x*h_x/tau)*pL.values[i][n_y]-pL.values[i+1][n_y]-pL.values[i-1][n_y];
	}
	O.data[steps_x-1] = L.values[steps_x-1][n_y];

	M.data[0][0] = 1;
	for (i=1; i<steps_x-1; i++) {
		M.data[i][i-1] = 1;
		M.data[i][i] = -2-2*h_x*h_x/tau;
		M.data[i][i+1] = 1;
	}
	M.data[steps_x-1][steps_x-1] = 1;

	NDVector stripe = tridiagonal_solve(M, O);
	for(i=1; i<steps_x-1; i++) {
		L.values[i][n_y] = stripe.data[i];
	}
	return L;
}


Layer3D build_x_stripe(Layer3D L, Layer3D pL, int n_x) {
		SquareMatrix M = getSquareMatrix(steps_y);
		NDVector O = getNDVector(steps_y);
		int i;

	O.data[0] = L.values[n_x][0];
	for(i=1; i<steps_y-1; i++) {
		O.data[i] = (2 - 2*h_y*h_y/tau)*pL.values[n_x][i]-pL.values[n_x][i+1]-pL.values[n_x][i-1];
	}
	O.data[steps_x-1] = L.values[n_x][steps_y-1];

	M.data[0][0] = 1;
	for (i=1; i<steps_y-1; i++) {
		M.data[i][i-1] = 1;
		M.data[i][i] = -2-2*h_y*h_y/tau;
		M.data[i][i+1] = 1;
	}
	M.data[steps_y-1][steps_y-1] = 1;

	NDVector stripe = tridiagonal_solve(M, O);
	for(i=1; i<steps_y-1; i++) {
		L.values[n_x][i] = stripe.data[i];
	}
	return L;
}

TimeLayer3D build_intermediate_layer(TimeLayer3D pTL) {
		int n_y;
		TimeLayer3D iTL;
		iTL.t = pTL.t+tau/2;
		iTL.layer3D = build_border(init_layer3D(steps_x, steps_y, h_x, h_y, -L, -L));

	for(n_y=1; n_y<steps_y-1; n_y++) {
		iTL.layer3D = build_y_stripe(iTL.layer3D, pTL.layer3D, n_y);
	}

	return iTL;
}


TimeLayer3D build_real_layer(TimeLayer3D pTL) {
		int n_x;
		TimeLayer3D rTL;
		rTL.t = pTL.t+tau/2;
		rTL.layer3D = build_border(init_layer3D(steps_x, steps_y, h_x, h_y, -L, -L));

	for(n_x=1; n_x<steps_x-1; n_x++) {
		rTL.layer3D = build_x_stripe(rTL.layer3D, pTL.layer3D, n_x);
	}

	return rTL;
}


TimeLayer3D* locally_1D_solve_in_square(double _L, MathFuncPointer _f_x_0, MathFuncPointer _f_x_1, MathFuncPointer _f_y_0,
		MathFuncPointer _f_y_1, MathFuncPointer2D _u_0, double _h_x, double _h_y, double _tau, double t, double write_interval) {
		L = _L;
		f_x_0 = _f_x_0; f_x_1 = _f_x_1; f_y_0 = _f_y_0; f_y_1 = _f_y_1;
		u_0 = _u_0; h_x = _h_x; h_y = _h_y;
		tau = _tau;

		int steps_t = t/tau+1, n_t;
		steps_x = 2*L/h_x+1, steps_y = 2*L/h_y+1;
		TimeLayer3D* TLs = calloc(t/write_interval+1, sizeof(TimeLayer3D));

	TLs[0] = build_initial_layer();
	TimeLayer3D prevTL = TLs[0];
	TimeLayer3D nextTL;
	int write_counter=1;

	for (n_t = 1; n_t<steps_t; n_t++) {
		nextTL = build_real_layer(build_intermediate_layer(prevTL));
		prevTL = nextTL;
		if((n_t % (int) (write_counter*write_interval/tau))==0) {
			TLs[write_counter] = nextTL;
			write_counter++;
		}
	}
	return TLs;

}
