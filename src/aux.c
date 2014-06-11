#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "aux.h"

double vec_abs(Vector2D V) {
	return sqrt(V.x1*V.x1+V.x2*V.x2);
}

Vector2D mul(Vector2D V, double factor) {
	Vector2D V1;
	V1.x1 = V.x1*factor;
	V1.x2 = V.x2*factor;
	return V1;
}
Vector2D sum(Vector2D V1, Vector2D V2) {
	Vector2D sum;
	sum.x1 = V1.x1 + V2.x1;
	sum.x2 = V1.x2 + V2.x2;
	return sum;

}

Vector2D sub(Vector2D V1, Vector2D V2) {
	Vector2D sub;
	sub.x1 = V1.x1 - V2.x1;
	sub.x2 = V1.x2 - V2.x2;
	return sub;

}

SquareMatrix copySquareMatrix(SquareMatrix M) {
			int i, j;
			SquareMatrix copy;

		copy = getSquareMatrix(M.dimension);
		for(i=0; i<M.dimension; i++) {
			for(j=0; j<M.dimension; j++) {
				copy.data[i][j] = M.data[i][j];
			}
		}

		return copy;
}

SquareMatrix getSquareMatrix(int dimension) {
		int i;
		SquareMatrix M;

	M.data = calloc(dimension, sizeof(double*));
	for(i=0; i<dimension; i++) {
		M.data[i] =  calloc(dimension, sizeof(double));

	}
	M.dimension = dimension;

	return M;
}

SquareMatrix fillTridiagonal(SquareMatrix M) {
		int i, j;

	for(j=0; j<M.dimension; j++)
		for (i=j-1; i<j+2; i++) {
			if(j>=0)
				M.data[j][i] = 5+i-j-4;
		}
	return M;
}

SquareMatrix mulRow(SquareMatrix M, int row, double factor) {

		int i;

	SquareMatrix copy = copySquareMatrix(M);
	for (i=0;i<M.dimension; i++)
		copy.data[row][i]=M.data[row][i]*factor;

	return copy;
}

SquareMatrix sumRows(SquareMatrix M, int row, int row_to_add) {
		int i;

	SquareMatrix copy = copySquareMatrix(M);
	for (i=0; i<M.dimension; i++) {
		copy.data[row][i] = M.data[row][i]+M.data[row_to_add][i];
	}

	return copy;
}

NDVector getNDVector(int dimension) {
		NDVector V;


	V.data =  calloc(dimension, sizeof(double));
	V.dimension = dimension;
	return V;
}

NDVector copyNDVector(NDVector V) {
		int i;
	NDVector copy = getNDVector(V.dimension);
	for (i = 0; i<V.dimension; i++)
		copy.data[i] = V.data[i];
	return copy;
}
