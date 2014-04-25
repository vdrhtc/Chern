#include "summarizer.h"
#include<stdio.h>
#include<math.h>

void summarize() {

		int n, lim = 20000000;
		double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		double sum_neg_up = 0, sum_neg_down = 0;
		double sum_pos_up = 0, sum_pos_down = 0;

	printf("From 1 to %d: ", lim);
	for (n = 1; n < lim+1; n++) {
		sum1 += pow(-1, n) / n;
	}
	printf("%.16f\n", sum1);

	printf("From 1 to %d pos+neg: ", lim);
	for (n = 1; n < lim+1; n++) {
		if (! (n % 2))
			sum_neg_up += pow(-1, n) / n;
		else
			sum_pos_up += pow(-1, n) / n;
	}
	sum4 = sum_neg_up + sum_pos_up;
	printf("%.16f | %.16f + %.16f\n", sum4, sum_neg_up, sum_pos_up);

	printf("From %d to 1: ", lim);
	for (n = lim; n > 0; n--) {
		sum2 += pow(-1, n) / n;
	}
	printf("%.16f\n", sum2);

	printf("From %d to 1 pos+neg: ", lim);
	for (n = lim; n > 0; n--) {
		if (!(n % 2))
			sum_neg_down += pow(-1, n) / n;
		else
			sum_pos_down += pow(-1, n) / n;
	}
	sum3 = sum_neg_down + sum_pos_down;
	printf("%.16f | %.16f + %.16f\n", sum3, sum_neg_down, sum_pos_down);
}
