/*
 * dft.h
 *
 *  Created on: 15 июня 2014 г.
 *      Author: gleb
 */

#ifndef DFT_H_
#define DFT_H_

Point2D* make_sample_rect_window(MathFuncPointer f, int N, double a, double L);
ParametricComplexPoint* discrete_fourier_transform(Point2D* sample, int N, double L);
Point2D* spectral_power(Point2D* sample, int N, double L);
Point2D* make_sample_hann_window(MathFuncPointer f, int N, double a, double L);
#endif /* DFT_H_ */
