#include <stdio.h>
#include <stdlib.h>
#include "funcList.h"

//typedef struct NODE {
//	double Coef;
//	int Ind;
//	struct NODE* link;
//
//}NODE;
//
//typedef struct NODELINK {
//	 NODE *head;
//	 NODE *tail;
//}NODELINK;
//
//
//int main() {
//
//	NODELINK list;
//	list.head = NULL;
//	list.tail = NULL;
//
//	/* f(x) = 6.7x4 + 3.2x^3 − x^2 + x − 2, 여기서 x ∈ [−10, 10] */
//	insertion(&list, 6.7,4);
//	insertion(&list, 3.2, 3);
//	insertion(&list, -1, 2);
//	insertion(&list, 1, 1);
//	insertion(&list, -2, 0);
//
//	print(&list);
//	for (double i = -10; i <= 10;) {
//		printf("\nf(x)에 %f를 대입한 값은 %f입니다.",i,calc(&list, i));
//		i += 0.5;
//	}
//	
//
//	freeAraay(&list);
//
//
//
//
//
//	return 0;
//}