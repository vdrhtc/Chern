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
	Point2D* points;
	int length;
} Point2DArray;

typedef struct {
	double x1;
	double x2;
	double x3;
} Point3D;

typedef struct {
	double t;
	Point2D* layer2D;
} TimeLayer2D;

typedef struct {
	double** values;
	int steps_x, steps_y;
	double h_x, h_y, x_0, y_0;
} Layer3D;

typedef struct {
	double t;
	Layer3D layer3D;
} TimeLayer3D;

typedef struct {
	double x1;
	double x2;
} Vector;


typedef struct {
	double t;
	Vector X;
} ParametricPoint2D;
typedef Vector (*VecMathFuncPointer2D)(Vector);
typedef double (*MathFuncPointer)(double);
typedef double (*MathFuncPointer2D)(double, double);

Vector mul(Vector, double);
Vector sum(Vector, Vector);
Vector sub(Vector, Vector);
double vec_abs(Vector);

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
Layer3D init_layer3D(int steps_x, int steps_y, double h_x, double h_y, double x_0, double y_0);

#endif /* AUX_H_ */
