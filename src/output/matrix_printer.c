#include<stdio.h>
#include<math.h>
#include "../aux.h"


void print_square_matrix_to_console(SquareMatrix M) {
			int i, j;

		printf("Matrix([");
		for (i=0; i<M.dimension; i++) {
			printf("[");
			for (j=0; j<M.dimension; j++) {
				printf("%f, ", M.data[i][j]);
			}
			printf("], ");
		}
		printf("])\n");
}

void print_ndvector_to_console(NDVector V) {

		int j;

	printf("Matrix([");
	for (j=0; j<V.dimension; j++) {
		printf("%f, ", V.data[j]);
	}
	printf("])\n");

}
