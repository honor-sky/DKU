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


void append(NODELINK* poly, double coef, int expon) {

	NODE* p = (NODE*)malloc(sizeof(NODE)); //새 노드를 동적으로 생성 

	p->coef = coef;
	p->expon = expon;

	if (poly->head == NULL) { // 리스트가 비어 있으면
		poly->head = p; // 새로운 노드를 첫번째 노드로 만든다.
	}
	else { // 리스트가 비어 있지 않으면
		poly->tail->link = p;// 새로운 노드를 이전 노드의 끝에

	}
	p->link = NULL; // 새로운 노드의 링크 필드를 NULL로 설정
	poly->tail = p;
}

void erase(NODELINK* poly) { //노드를 지워준다 //첫 노드부터 모두 지움
	NODE* p = poly->head;
	NODE* next;
	while (p != NULL)
	{
		next = p->link;
		free(p);
		p = next;
	}
}

/*항을 크기순으로 정렬하는 함수 추가 작성*/
void sort(NODELINK* poly) {
	NODE* p = poly->head;
	NODE* pp = p->link;
	double tem_coef;
	double tem_expon;

	while (p != NULL) {
		pp = p->link;
		while (pp != NULL) {
			if (p->expon < pp->expon) {
				tem_coef = p->coef;
				tem_expon = p->expon;
				p->coef = pp->coef;
				p->expon = pp->expon;
				pp->coef = tem_coef;
				pp->expon = tem_expon;
			}
			pp = pp->link;
		}
		p = p->link;

	}
}
/*원형 링크드 리스트 -> 항의 앞뒤의 항 정보를 가지고 있음 -> 한 번 정렬 한 다음엔 굳이 모든 비교 필요 없을지도?...*/

void print(NODELINK* poly) {
	NODE* p = poly->head; //p가 연결리스트의 가장 첫번째 노드 head부터 가르킴
	printf("f(x)=");

	while (p != NULL) //p가 더이상 가르킬 노드가 없을 때까지
	{
		printf("+(%fx^%d)",  p->coef, p->expon);
		p = p->link; //node->head->link 와 동일
	}
	printf("\n");
}

/*다항식의 덧셈*/
NODELINK *poly_add(NODELINK *a, NODELINK *b) { //다항식의 덧셈 진행 후 새로운 다항식 노드에 대한 포인터를 반환
	sort(a);
	sort(b);
	NODE* p1 = a->head;
	NODE* p2 = b->head;

	NODELINK poly_sum;
	poly_sum.head = NULL;
	poly_sum.tail = NULL;

	while (p1 != NULL && p2 != NULL) {
		if (p1->expon == p2->expon) {
			append(&poly_sum, p1->coef + p2->coef, p1->expon);
			p1 = p1->link;
			p2 = p2->link;
		}
		else if(p1->expon > p2->expon){
			append(&poly_sum, p1->coef, p1->expon);
			p1 = p1->link;
		}
		else if (p1->expon < p2->expon) {
			append(&poly_sum, p2->coef, p2->expon);
			p2 = p2->link;
		}
		else if(p1 == NULL){
			append(&poly_sum, p2->coef, p2->expon);
			p2 = p2->link;
		}
		else if (p2 == NULL) {
			append(&poly_sum, p1->coef, p1->expon);
			p1 = p1->link;
		}
	}
	return &poly_sum;
	
}

/*다항식의 뺄셈*/
NODELINK* poly_minu(NODELINK* a, NODELINK* b) { //a - b
	sort(a);
	sort(b);
	NODE* p1 = a->head;
	NODE* p2 = b->head;

	NODELINK poly_re;
	poly_re.head = NULL;
	poly_re.tail = NULL;

	while (p1 != NULL && p2 != NULL) {
		if (p1->expon == p2->expon) {
			append(&poly_re, p1->coef - p2->coef, p1->expon);
			p1 = p1->link;
			p2 = p2->link;
		}
		else if (p1->expon > p2->expon) {
			append(&poly_re, p1->coef, p1->expon);
			p1 = p1->link;
		}
		else if (p1->expon < p2->expon) {
			append(&poly_re, -p2->coef, p2->expon);
			p2 = p2->link;
		}
		else if (p1 == NULL) {
			append(&poly_re, -p2->coef, p2->expon);
			p2 = p2->link;
		}
		else if (p2 == NULL) {
			append(&poly_re, p1->coef, p1->expon);
			p1 = p1->link;
		}
	}
	return &poly_re;

}