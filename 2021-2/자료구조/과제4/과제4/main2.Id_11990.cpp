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
	append(poly2, 1, 5,0);
	append(poly2, 2.5, 1, 1);
	append(poly2, -3, 2, 2);
	append(poly2, 4.1, 0, 3);
	append(poly2, 2, 7, 4);
	//print(poly2,5);
		
	
	TERM poly3[7];
	//f(x) = x^8 + x^6 + x^5 + x^4 + x^3 + x + 2
	append(poly3, 1, 8, 0);
	append(poly3, 1, 6, 1);
	append(poly3, 1, 5, 2);
	append(poly3, 1, 4, 3);
	append(poly3, 1, 3, 4);
	append(poly3, 1, 1, 5);
	append(poly3, 2, 0, 6);
	//print(poly3,7);	
	
	TERM poly4[5];
	////f(x) = -x + 3x^5 + 2.7x^3 - 4x^2 -5.5
	append(poly4, -1, 1,0);
	append(poly4, 3, 5,1);
	append(poly4, 2.7, 3,2);
	append(poly4, -4, 2,3);
	append(poly4, -5.5, 0,4);
	//print(poly4,5);
	

	TERM poly5[5];
	////f(x) = 10x^2 + 2.4x^3 -1.5 - x - 3.6x^5
	append(poly5, 10, 2,0);
	append(poly5, 2.4, 3,1);
	append(poly5, -1.5, 0,2);
	append(poly5, -1, 1,3);
	append(poly5, -3.6, 5,4);
	//print(poly5,5);

	//printf("%d", sizeof(poly1)/sizeof(TERM));
	TERM result[7];
	poly_add(poly1,5 ,poly2,5 ,result);
	prin