#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int i;
	struct node* link;
}NODE;

NODE* head = NULL;
NODE* p;
NODE* prev;
int pos_z;
NODE* next;

int main(void) {
	while (1) {
		printf("���� ������ �Է��ϼ���(���� -1):");
		scanf("%d", &pos_z);
		if (pos_z == -1) {
			break;
		}
		p = (NODE*)malloc(sizeof(NODE));
		p->i = pos_z;

		//��� ����
		if (head == NULL) {
			head = p;
		}
		else {
			prev->link = p;
		}

		p->link = NULL;//���� ��� ���� ��, ���� �ϱ� ���ؼ� link�κ� NULL�� ����
		prev = p; //���� ��� ���� ��, p�� �װ� ����Ű�Ƿ� ���� ���� prev�� ����Ű���� ����
	}

	//���
	p = head; //ó������ ¤��� ����ؾ� �ϴϱ�...ó������..
	while (p != NULL) {
		printf("%d->", p->i);
		p = p->link;//���� ���� �Ѿ
	}
	printf("NULL");
	//�����޸� ��ȯ
	p = head;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}

	return 0;
}









