#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

typedef struct NODE {
	double coef;
	int expon;
	struct NODE* link;
}NODE;

typedef struct NODELINK { 
	struct NODE* head;
	struct NODE* tail;
}NODELINK;


int main() {

	NODELINK poly1;
	poly1.head = NULL;
	poly1.tail = NULL;

	//f(x) = 6.7x^4 + 3.2x ^ 3 − x ^ 2 + x − 2
	append(&poly1, 6.7,4);
	append(&poly1, 3.2, 3);
	append(&poly1, -1, 2);
	append(&poly1, 1, 1);
	append(&poly1, -2, 0);
	//print(&poly1);

	NODELINK poly2;
	poly2.head = NULL;
	poly2.tail = NULL;

	//f(x) = x^5 + 2.5x -3x^2 + 4.1 + 2x^7
	append(&poly2, 1,5);
	append(&poly2, 2.5,1);
	append(&poly2, -3, 2);
	append(&poly2, 4.1, 0);
	append(&poly2, 2, 7);
	//print(&poly2);

	NODELINK poly3;
	poly3.head = NULL;
	poly3.tail = NULL;

	////f(x) = x^8 + x^6 + x^5 + x^4 + x^3 + x + 2
	append(&poly3, 1,8);
	append(&poly3, 1,6);
	append(&poly3, 1,5);
	append(&poly3, 1,4);
	append(&poly3, 1, 3);
	append(&poly3, 1, 1);
	append(&poly3, 2, 0);
	//print(&poly3);

	NODELINK poly4;
	poly4.head = NULL;
	poly4.tail = NULL;

	////f(x) = -x + 3x^5 + 2.7x^3 - 4x^2 -5.5
	append(&poly4, -1,1);
	append(&poly4, 3,5);
	append(&poly4, 2.7,3);
	append(&poly4, -4,2);
	append(&poly4, -5.5,0);
	//print(&poly4);

	NOD