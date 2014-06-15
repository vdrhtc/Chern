/*
 * aux.h
 *
 *  Created on: 27 мая 2014 г.
 *      Author: gleb
 */

#include<complex.h>

#ifndef AUX_H_
#define AUX_H_

typedef struct {
	double complex Z;
	double k;
} ParametricComplexPoint;

typedef struct {
	double x2;
	double x1;

} Point2D;

typedef struct {
	double t;
	Point2D* layer2D;
} TimeLayer2D;

typedef struct {
	double x1;
	double x2;
} Vector2D;


typedef struct {
	double t;
	Vector2D X;
} ParametricPoint2D;
typedef Vector2D (*VecMathFuncPointer2D)(Vector2D);
typedef double (*MathFuncPointer)(double);

Vector2D mul(Vector2D, double);
Vector2D sum(Vector2D, Vector2D);
Vector2D sub(Vector2D, Vector2D);
double vec_abs(Vector2D);

typedef struct {
	double** data;
	int dimension;
} SquareMatrix;

typedef struct {
	double * data;
	int dimension;
} NDVector;

typedef struct {
	SquareMatrix M;
	NDVector V;
} LinearSystem;

SquareMatrix getSquareMatrix(int);
SquareMatrix fillTridiagonal(SquareMatrix);
SquareMatrix mulRow(SquareMatrix, int row, double factor);
SquareMatrix sumRows(SquareMatrix, int row1, int row2);
SquareMatrix copySquareMatrix(SquareMatrix);
NDVector copyNDVector(NDVector);
NDVector getNDVector(int);

#endif /* AUX_H_ */
