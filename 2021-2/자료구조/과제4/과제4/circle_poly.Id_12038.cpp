#include <stdio.h>
#include <stdlib.h>
#include "circle_poly.h"

/*배열과 구조체로 작성*/
typedef struct TERM {
	double coef;
	int expon;
}TERM;

void append(TERM *poly, double coef, int expon,int arr) {
	(poly +arr)->coef = coef;
	(poly+arr)->expon = expon;

}

void sort(TERM *poly,int n) {
	int tmp_expon;
	double tmp_coef;
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if ((poly+j)->expon > (poly+i)->expon) {

				tmp_expon = (poly + i)->expon;
				tmp_coef = (poly + i)->coef;
				(poly + i)->expon = (poly + j)->expon;
				(poly + i)->coef = (poly + j)->coef;
				(poly + j)->expon = tmp_expon;
				(poly + j)->coef= tmp_coef;
			}
		}
	}
}

void print(TERM *poly,int n) {
	int i;
	printf("f(x)=");
	for (i = 0; i < n; i++) {
		printf("+(%fx^%d)", (poly + i)->coef, (poly + i)->expon);
	}
	printf("\n");
}


///*다항식의 덧셈*/
void poly_add(TERM* a, int asize,TERM* b,int bsize,TERM*c) { //다항식의 덧셈 진행 후 새로운 다항식 노드에 대한 포인터를 반환

	sort(a, asize);
	sort(b, bsize);

	int i=0;
	int j = 0;
	int count = 0;
	while(i!=asize&&j!=bsize) {
		if ((a+i)->expon == (b+j)->expon) {
			(c + count)->coef = (a + i)->coef+ (b + i)->coef;
			(c + count)->expon = (a + i)->expon;
			i++;
			j++;
			count++;
		}
		else if((a + i)->expon > (b + j)->expon) {
			(c + count)->coef = (a + i)->coef;
			(c + count)->expon = (a + i)->expon;
			i++;
			count++;
		}
		else if ((a + i)->expon < (b + j)->expon) {
			(c + count)->coef = (b + j)->coef;
			(c + count)->expon = (b + j)->expon;
			j++;
			count++;
		}
		else if (i== asize) {
			(c + count)->coef = (b + j)->coef;
			(c + count)->expon = (b + j)->expon;
			j++;
			count++;
		}
		else if (j==bsize){
			(c + count)->coef = (a + i)->coef;
			(c + count)->expon = (a + i)->expon;
			i++;
			count++;
		}
						
	}
}

/*다항식의 뺄셈*/
void poly_minu(TERM* a, int asize, TERM* b, int bsize, TERM* c) { //다항식의 덧셈 진행 후 새로운 다항식 노드에 대한 포인터를 반�