#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "../aux.h"
#include "complex.h"

ParametricComplexPoint* discrete_fourier_transform(Point2D* sample, int N, double L) {

		ParametricComplexPoint* transform = calloc(N, sizeof(ParametricComplexPoint));
		int k, n;

	for (k=0; k<N; k++) {
		transform[k].k = 2*M_PI*k/L;
			for (n=0; n<N; n++) {
				transform[k].Z += sample[n].x2*cexp(-I*2*M_PI*k/L*sample[n].x1);
		}
		transform[k].Z /= N;
	}
	return transform;
}


Point2D* spectral_power(Point2D* sample, int N, double L) {

		int i;
		Point2D* power_spectrum = calloc(N, sizeof(Point2D));

	ParametricComplexPoint* transform = discrete_fourier_transform(sample, N, L);
	for (i=0; i<N; i++) {
		power_spectrum[i].x1 = transform[i].k;
		power_spectrum[i].x2 = pow(cabs(transform[i].Z),2);
	}
	return power_spectrum;
}

Point2D* make_sample_rect_window(MathFuncPointer f, int N, double a, double L) {

		double step = L/N;
		int n;
		Point2D * sample = calloc(N, sizeof(Point2D));

	for (n=0; n<N; n++) {
		sample[n].x1 = a+n*step;
		sample[n].x2 = f(a+n*step);
	}
	return sample;
}

Point2D* make_sample_hann_window(MathFuncPointer f, int N, double a, double L) {
		double step = L/N;
		int n;
		Point2D* sample = calloc(N, sizeof(Point2D));

	for (n=0; n<N; n++) {
			sample[n].x1 = a+n*step;
			sample[n].x2 = f(a+n*step)*0.5*(1-cos(2*M_PI*n/(N-1)));
	}

	return sample;
}
