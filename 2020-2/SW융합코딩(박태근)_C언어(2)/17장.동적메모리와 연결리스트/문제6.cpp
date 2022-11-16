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
		printf("\n연결 리스트를 이용한 전화 번호부 메뉴\n");
		printf("================================\n");
		printf("1. 초기화\n2. 전화 번호 추가\n3. 전화 번호 탐색\n4. 전화 번호 변경\n5. 종료\n");
		printf("================================\n");
		printf("번호를 입력하세요:");

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
		printf("이름('z'시 초기화 종료):");
		scanf("%s", buffer);  //gets_s를 쓰면 넘어가는 이유가 뭘까…?
		if (strcmp(buffer, "z") == 0) {
			break;
		}
		p = (PHONE*)malloc(sizeof(PHONE));
		if (p == NULL) {
			printf("동적 메모리 할당 오류!\n");
			exit(1);
		}
		strcpy(p->name, buffer);
		printf("번호: ");
		scanf("%s", p->number);

		head = p;
		p->link = NULL;
		prev = p;
		fflush(stdout);
	}
	free(p);
	return;

} //초기화 두번 할 경우 버그 수정

void add_num() {
	p = (PHONE*)malloc(sizeof(PHONE));
	if (p == NULL) {
		printf("동적 메모리 할당 오류!\n");
		exit(1);
	}
	printf("이름: ");
	scanf("%s", p->name);
	printf("번호: ");
	scanf("%s", p->number);
	printf("\n추가되었습니다.\n");

	prev->link = p;
	p->link = NULL;
	prev = p;
	free(p);
	return;
}
void search_num(void) {
	char search_name[10];
	printf("찾고 싶은 번호의 이름을 입력하시오: ");
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
		printf("찾으시는 이름의 번호가 존재하지 않습니다.\n");
	}
	return;
}
void change_num(void) {
	char name[10];
	char number[30];

	printf("변경하고 싶은 번호의 이름을 입력하시오:");
	scanf("%s", name);

	p = head;
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) { //변경할 번호의 이름 찾음
			break;
		}
		else {
			p = p->link;
		}
	}
	if (p == NULL) {
		printf("변경하실 이름의 번호가 존재하지 않습니다.\n");
	}
	printf("새로운 번호를 입력하시오:");
	scanf("%s", number);
	strcpy(p->number, number);
	printf("변경 되었습니다.\n");
	return;
}










