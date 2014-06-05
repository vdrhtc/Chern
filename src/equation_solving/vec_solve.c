#include<stdio.h>
#include<math.h>
#include "../aux.h"

double partial_1st_component(VecMathFuncPointer2D f, Vector2D point,
		int variable_index) {
	//variable_index == 0 <=> x
	//variable_index == 1 <=> y

	if (variable_index == 0) {
		//x
		double step = 1e-13;
		Vector2D point_before;
		point_before.x1 = point.x1 - step;
		point_before.x2 = point.x2;
		Vector2D point_after;
		point_after.x1 = point.x1 + step;
		point_after.x2 = point.x2;

		return (f(point_after).x1 - f(point_before).x1) /2/ step;
	}


	else {
		//y
		double step = 1e-13;
		Vector2D point_before;
		point_before.x2 = point.x2 - step;
		point_before.x1 = point.x1;
		Vector2D point_after;
		point_after.x2 = point.x2 + step;
		point_after.x1 = point.x1;

		return (f(point_after).x1 - f(point_before).x1) /2/ step;

	}
}

double partial_2nd_component(VecMathFuncPointer2D f, Vector2D point,
		int variable_index) {
	//variable_index == 0 <=> x
	//variable_index == 1 <=> y

	if (variable_index == 0) {
		//x
		double step = 1e-13;
		Vector2D point_before;
		point_before.x1 = point.x1 - step;
		point_before.x2 = point.x2;
		Vector2D point_after;
		point_after.x1 = point.x1 + step;
		point_after.x2 = point.x2;

		return (f(point_after).x2 - f(point_before).x2) / 2/  step;
	}


	else {
		//y
		double step = 1e-13;
		Vector2D point_before;
		point_before.x2 = point.x2 - step;
		point_before.x1 = point.x1;
		Vector2D point_after;
		point_after.x2 = point.x2 + step;
		point_after.x1 = point.x1;

		return (f(point_after).x2 - f(point_before).x2) / 2 /step;

	}
}

Vector2D vec_newton_solve(VecMathFuncPointer2D f, Vector2D V_0) {

	double invtimestep = 1e4;

	Vector2D V_next;
	Vector2D V_old = V_0;
	double tolerance = pow(10, (int)(log10(fabs(f(V_old).x1))))/1e5;
	while (fabs(f(V_old).x1) > tolerance || fabs(f(V_old).x2) > tolerance) {
		double A_1 = invtimestep-998;//partial_1st_component(f, V_old, 0);
		double B_1 = -1998;//partial_1st_component(f, V_old, 1);
		double A_2 = 999;//partial_2nd_component(f, V_old, 0);
		double B_2 = invtimestep+1999;//partial_2nd_component(f, V_old, 1);

		double f_1 = f(V_old).x1;
		double f_2 = f(V_old).x2;


		double common_factor = 1/(A_1*B_2-A_2*B_1);

		V_next.x1 = common_factor*(A_1*B_2*V_old.x1 - A_2*B_1*V_old.x1+B_1*f_2-B_2*f_1);
		V_next.x2 = common_factor*(A_1*B_2*V_old.x2 - A_2*B_1*V_old.x2-A_1*f_2+A_2*f_1);

		V_old = V_next;
	}
	return V_old;
}
