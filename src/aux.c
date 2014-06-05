#include<stdio.h>
#include<math.h>
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
