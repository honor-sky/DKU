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


void append(NODELINK* poly, double coef, int expon) {

	NODE* p = (NODE*)malloc(sizeof(NODE)); //�� ��带 �������� ���� 

	p->coef = coef;
	p->expon = expon;

	if (poly->head == NULL) { // ����Ʈ�� ��� ������
		poly->head = p; // ���ο� ��带 ù��° ���� �����.
	}
	else { // ����Ʈ�� ��� ���� ������
		poly->tail->link = p;// ���ο� ��带 ���� ����� ����

	}
	p->link = NULL; // ���ο� ����� ��ũ �ʵ带 NULL�� ����
	poly->tail = p;
}

void erase(NODELINK* poly) { //��带 �����ش� //ù ������ ��� ����
	NODE* p = poly->head;
	NODE* next;
	while (p != NULL)
	{
		next = p->link;
		free(p);
		p = next;
	}
}

/*���� ũ������� �����ϴ� �Լ� �߰� �ۼ�*/
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
/*���� ��ũ�� ����Ʈ -> ���� �յ��� �� ������ ������ ���� -> �� �� ���� �� ������ ���� ��� �� �ʿ� ��������?...*/

void print(NODELINK* poly) {
	NODE* p = poly->head; //p�� ���Ḯ��Ʈ�� ���� ù��° ��� head���� ����Ŵ
	printf("f(x)=");

	while (p != NULL) //p�� ���̻� ����ų ��尡 ���� ������
	{
		printf("+(%fx^%d)",  p->coef, p->expon);
		p = p->link; //node->head->link �� ����
	}
	printf("\n");
}

/*���׽��� ����*/
NODELINK *poly_add(NODELINK *a, NODELINK *b) { //���׽��� ���� ���� �� ���ο� ���׽� ��忡 ���� �����͸� ��ȯ
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

/*���׽��� ����*/
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