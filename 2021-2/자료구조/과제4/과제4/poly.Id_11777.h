#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"


typedef struct NODE {
	double coef;
	int expon;
	struct NODE* link;
}NODE;

typedef struct NODELINK { //������ �������ֱ� ���� ����ü
	struct NODE* head;
	struct NODE* tail;
}NODELINK;


void 