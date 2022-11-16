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
		printf("양의 정수를 입력하세요(종료 -1):");
		scanf("%d", &pos_z);
		if (pos_z == -1) {
			break;
		}
		p = (NODE*)malloc(sizeof(NODE));
		p->i = pos_z;

		//노드 연결
		if (head == NULL) {
			head = p;
		}
		else {
			prev->link = p;
		}

		p->link = NULL;//다음 노드 생성 시, 연결 하기 위해서 link부분 NULL로 만듬
		prev = p; //다음 노드 생성 시, p가 그걸 가리키므로 이전 노드는 prev가 가리키도록 만듬
	}

	//출력
	p = head; //처음부터 짚어가며 출력해야 하니깐...처음부터..
	while (p != NULL) {
		printf("%d->", p->i);
		p = p->link;//다음 노드로 넘어감
	}
	printf("NULL");
	//동적메모리 반환
	p = head;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}

	return 0;
}









