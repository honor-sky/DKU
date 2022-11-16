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
	NODE* p = poly->head; //p�� ���Ḯ��Ʈ�� ���� ù���