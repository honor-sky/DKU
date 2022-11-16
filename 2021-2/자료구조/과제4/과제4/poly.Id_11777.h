#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"


typedef struct NODE {
	double coef;
	int expon;
	struct NODE* link;
}NODE;

typedef struct NODELINK { //노드들을 연결해주기 위한 구조체
	struct NODE* head;
	struct NODE* tail;
}NODELINK;


void 