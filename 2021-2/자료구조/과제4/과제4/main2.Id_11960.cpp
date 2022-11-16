#include <stdio.h>
#include <stdlib.h>
#include "circle_poly.h"

typedef struct TERM {
	double coef;
	int expon;
}TERM;

int main() {

	TERM poly1[5];
	append(poly1, -2, 0, 0);
	append(poly1, 3.2, 3,1);
	append(poly1, -1, 2,2);
	append(poly1, 1, 1,3);
	append(poly1, 6.7, 4, 4);
	//print(poly1,5);

	TERM poly2[5];
	append(poly2, 1, 5,