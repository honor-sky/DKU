#include <stdio.h>
#include "circleQueue.h"
#define nsize 20

struct cqueue {  //����ť ����ü
	int front;
	int rear;
	int lastOperation; //������ �������� üũ ���� //���Ҹ� ������ +1 ���� -1
	char queue[nsize];
};

/*���ڿ� ���ڸ� ���� ����ť�� ���޹ް� ó��*/
void enqueue(struct cqueue*que, char a) {
	if (que->lastOperation==nsize) { //������ ����� ť�� ��� ��
		printf("enqueue�Ұ�:����ť�� �� ���� %c �� ���� ���մϴ�.\n",a);
	}
	else {
		if(que->lastOperation == 0) {//������ ��� ���� �Ǵ� ���
			que->queue[que->rear] = a; //rear==front �̹Ƿ� rear �̵� ����
		}
		else {  //������ ���굵, ����ִ� ť�� �ƴ� ���
			que->rear = (que->rear + 1) % nsize; //rear�̵� 
			que->queue[que->rear] = a;
		}
		
		printf("enqueue:%c �� ����ť�� �ֽ��ϴ�.\n",a);
		que->lastOperation++;
	}

}
/*����ť���� ���� ��(������� �� ���Ұ� ����)*/
void dequeue(struct cqueue*que) {
	if (que->lastOperation == 0) {
		printf("dequeue�Ұ�: ����ť�� ����ֽ��ϴ�.\n");	
	}
	else {
		printf("dequeue:%c �� ����ť���� ���ϴ�.\n", que->queue[que->front]);
		que->queue[que->front] = NULL;
		que->lastOperation--;
		if (que->lastOperation != 0) { //dequeue��, ����ִ� ť�� �ƴ� ���
			que->front = (que->front + 1) % nsize; //front �̵��� ���� ���Ҹ� ���� ������ ����Ŵ
		}
	}

}
/*����ť�� ���� Ȯ��*/
void isEmpty(struct cqueue*que) {
	if (que->lastOperation < nsize) {
		printf("����ť�� ������ �ֽ��ϴ�.\n");
	}
	else {
		printf("����ť�� �� á���ϴ�.\n");
	}
}
/*����ť ���� ���*/
void print(struct cqueue* que) {
	printf("���� ����ť�� ����Դϴ�.\n");

	if (que->front < que->rear) {
		for (int i = que->front; i <= que->rear; i++) {
			printf("%c", que->queue[i]);
		}
	}
	else if (que->front > que->rear) {
		for (int i = que->front; i < nsize; i++) {
			printf("%c", que->queue[i]);
		}
		for (int i = 0; i <= que->rear; i++) {
			printf("%c", que->queue[i]);
		}
	}
	else if(que->front== que->rear){
		printf("%c", que->queue[que->front]);
	}
	
}
