#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_book {
	char name[10];
	char number[20];
	struct phone_book* link;
}PHONE;

PHONE* p;
PHONE* head = NULL;
PHONE* prev;
PHONE* next;
char buffer[20];

void init(void);
void add_num();
void search_num();
void change_num();
void menu();

int main(void) {
	menu();
	return 0;
}

void menu() {
	while (1) {
		printf("\n���� ����Ʈ�� �̿��� ��ȭ ��ȣ�� �޴�\n");
		printf("================================\n");
		printf("1. �ʱ�ȭ\n2. ��ȭ ��ȣ �߰�\n3. ��ȭ ��ȣ Ž��\n4. ��ȭ ��ȣ ����\n5. ����\n");
		printf("================================\n");
		printf("��ȣ�� �Է��ϼ���:");

		int key;
		scanf("%d", &key);
		if (key == 1) {
			init();
		}
		else if (key == 2) {
			add_num();
		}
		else if (key == 3) {
			search_num();
		}
		else if (key == 4) {
			change_num();
		}
		else {
			break;
		}
	}
	return;
}
void init(void) {
	while (1) {
		printf("�̸�('z'�� �ʱ�ȭ ����):");
		scanf("%s", buffer);  //gets_s�� ���� �Ѿ�� ������ ���?
		if (strcmp(buffer, "z") == 0) {
			break;
		}
		p = (PHONE*)malloc(sizeof(PHONE));
		if (p == NULL) {
			printf("���� �޸� �Ҵ� ����!\n");
			exit(1);
		}
		strcpy(p->name, buffer);
		printf("��ȣ: ");
		scanf("%s", p->number);

		head = p;
		p->link = NULL;
		prev = p;
		fflush(stdout);
	}
	free(p);
	return;

} //�ʱ�ȭ �ι� �� ��� ���� ����

void add_num() {
	p = (PHONE*)malloc(sizeof(PHONE));
	if (p == NULL) {
		printf("���� �޸� �Ҵ� ����!\n");
		exit(1);
	}
	printf("�̸�: ");
	scanf("%s", p->name);
	printf("��ȣ: ");
	scanf("%s", p->number);
	printf("\n�߰��Ǿ����ϴ�.\n");

	prev->link = p;
	p->link = NULL;
	prev = p;
	free(p);
	return;
}
void search_num(void) {
	char search_name[10];
	printf("ã�� ���� ��ȣ�� �̸��� �Է��Ͻÿ�: ");
	scanf("%s", search_name);

	p = head;
	while (p != NULL) {
		if (strcmp(p->name, search_name) == 0) {
			break;
		}
		else {
			p = p->link;
			printf("\n%s\n", p->number);
		}
	}
	if (p == NULL) {
		printf("ã���ô� �̸��� ��ȣ�� �������� �ʽ��ϴ�.\n");
	}
	return;
}
void change_num(void) {
	char name[10];
	char number[30];

	printf("�����ϰ� ���� ��ȣ�� �̸��� �Է��Ͻÿ�:");
	scanf("%s", name);

	p = head;
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) { //������ ��ȣ�� �̸� ã��
			break;
		}
		else {
			p = p->link;
		}
	}
	if (p == NULL) {
		printf("�����Ͻ� �̸��� ��ȣ�� �������� �ʽ��ϴ�.\n");
	}
	printf("���ο� ��ȣ�� �Է��Ͻÿ�:");
	scanf("%s", number);
	strcpy(p->number, number);
	printf("���� �Ǿ����ϴ�.\n");
	return;
}










