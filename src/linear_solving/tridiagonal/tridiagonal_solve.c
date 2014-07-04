#include<stdio.h>
#include<math.h>
#include "../../aux.h"
#include "../../output/matrix_printer.h"

LinearSystem discreteSin(double h, double a, double b) {

		int steps = round((b-a)/h)+1;
		int i, dimension=steps;
		SquareMatrix M = getSquareMatrix(dimension);
		NDVector V = getNDVector(dimension);

	V.data[0] = -sin(a);
	for (i=1; i<dimension-1; i++) {
		V.data[i] = 0;
	}
	V.data[dimension-1] = -sin(b);

	M.data[0][0] = 1;
	for (i=1; i<dimension-1; i++) {
		M.data[i][i-1] = 1;
		M.data[i][i] = -2+h*h;
		M.data[i][i+1] = 1;
	}
	M.data[dimension-1][dimension-1] = 1;
	LinearSystem L;
	L.M = M;
	L.V = V;
	return L;
}

LinearSystem elimination(SquareMatrix M, NDVector ordinal) {

		int row;

	SquareMatrix copy = copySquareMatrix(M);
	NDVector o_copy = copyNDVector(ordinal);


	for (row=0; row<M.dimension-1; row++) {
		int active_column = row;


		o_copy.data[row]*=1/copy.data[row][active_column];
		copy = mulRow(copy, row, 1/copy.data[row][active_column]);

		if(copy.data[row+1][active_column]==0)
			continue;

		o_copy.data[row+1]*= -1/copy.data[row+1][active_column];
		copy = mulRow(copy, row+1, -1/copy.data[row+1][active_column]);

		o_copy.data[row+1] += o_copy.data[row];
		copy = sumRows(copy, row+1, row);

	}


	o_copy.data[row]*= 1/copy.data[copy.dimension-1][copy.dimension-1];
	copy = mulRow(copy, row, 1/copy.data[copy.dimension-1][copy.dimension-1]);

	LinearSystem L;
	L.M = copy; L.V = o_copy;
	return L;
}

NDVector backsubs(LinearSystem L) {

		int i;
		NDVector solution = getNDVector(L.M.dimension);

	solution.data[L.M.dimension-1] = L.V.data[L.M.dimension-1];
	for (i=L.M.dimension-2; i>=0; i--) {
		solution.data[i] = L.V.data[i]-L.M.data[i][i+1]*solution.data[i+1];
	}
	return solution;
}

NDVector tridiagonal_solve(SquareMatrix M, NDVector ordinal) {
	LinearSystem eliminated = elimination(M, ordinal);
	return backsubs(eliminated);
}
