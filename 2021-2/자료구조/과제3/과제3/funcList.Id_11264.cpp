#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcList.h"

typedef struct NODE {
	double coef;
	int Ind;
	struct NODE* link;
}NODE;

typedef struct NODELINK { //노드들을 연결해주기 위한 구조체
	struct NODE* head;
	struct NODE* tail;
}NODELINK;


void insertion(NODELINK* nod, double coef, int Ind) {
	NODE* p = (NODE*)malloc(sizeof(NODE)); //새 노드를 동적으로 생성 

	p->coef = coef;
	p->Ind = Ind;

	if (nod->head == NULL) { // 리스트가 비어 있으면
		nod->head = p; // 새로운 노드를 첫번째 노드로 만든다.
	}
	else { // 리스트가 비어 있지 않으면
		nod->tail->link = p;// 새로운 노드를 이전 노드의 끝에

	}
	p->link = NULL; // 새로운 노드의 링크 필드를 NULL로 설정
	nod->tail = p;
}

void print(struct NODELINK* nod) {
	NODE* p = nod->head; //p가 연결리스트의 가장 첫번째 노드 head부터 가르킴

	while (p != NULL) //p가 더이상 가르킬 노드가 없을 때까지
	{
		printf("지수:%d 계수:%f \n", p->Ind, p->coef);
		p = p->link; //node->head->link 와 동일
	}
}

void freeAraay(struct NODELINK* nod) {
	NODE* p = nod->head;
	NODE* next;
	while (p != NULL)
	{
		next = p->link;
		free(p);
		p = next;
	}
}

double calc(struct NODELINK* nod,double n){
	NODE* p = nod->head;
	double result = 0;

	while (p != NULL) //p가 더이상 가르킬 노드가 없을 때까지
	{
		result += (p->coef) *pow(n,(p->Ind));
		p = p->link; //node->head->link 와 동일
	}
	return result;
}

