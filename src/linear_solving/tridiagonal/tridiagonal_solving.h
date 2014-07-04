/*
 * tridiagonal_solving.h
 *
 *  Created on: 11 июня 2014 г.
 *      Author: gleb
 */

#ifndef TRIDIAGONAL_SOLVING_H_
#define TRIDIAGONAL_SOLVING_H_

LinearSystem elimination(SquareMatrix M, NDVector ordinal);
NDVector tridiagonal_solve(SquareMatrix M, NDVector ordinal);
LinearSystem discreteSin(double h, double a, double b);
#endif /* TRIDIAGONAL_SOLVING_H_ */
