#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcList.h"

typedef struct NODE {
	double coef;
	int Ind;
	struct NODE* link;
}NODE;

typedef struct NODELINK { //������ �������ֱ� ���� ����ü
	struct NODE* head;
	struct NODE* tail;
}NODELINK;


void insertion(NODELINK* nod, double coef, int Ind) {
	NODE* p = (NODE*)malloc(sizeof(NODE)); //�� ��带 �������� ���� 

	p->coef = coef;
	p->Ind = Ind;

	if (nod->head == NULL) { // ����Ʈ�� ��� ������
		nod->head = p; // ���ο� ��带 ù��° ���� �����.
	}
	else { // ����Ʈ�� ��� ���� ������
		nod->tail->link = p;// ���ο� ��带 ���� ����� ����

	}
	p->link = NULL; // ���ο� ����� ��ũ �ʵ带 NULL�� ����
	nod->tail = p;
}

void print(struct NODELINK* nod) {
	NODE* p = nod->head; //p�� ���Ḯ��Ʈ�� ���� ù��° ��� head���� ����Ŵ

	while (p != NULL) //p�� ���̻� ����ų ��尡 ���� ������
	{
		printf("����:%d ���:%f \n", p->Ind, p->coef);
		p = p->link; //node->head->link �� ����
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

	while (p != NULL) //p�� ���̻� ����ų ��尡 ���� ������
	{
		result += (p->coef) *pow(n,(p->Ind));
		p = p->link; //node->head->link �� ����
	}
	return result;
}

