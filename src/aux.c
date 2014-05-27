#include<stdio.h>
#include<math.h>
#include "main.h"
#include "aux.h"


Vector mul(Vector V, double factor) {
	Vector V1;
	V1.x = V.x*factor;
	V1.y = V.y*factor;
	return V1;
}
Vector sum(Vector V1, Vector V2) {
	Vector sum;
	sum.x = V1.x + V2.x;
	sum.y = V1.y + V2.y;
	return sum;

}
