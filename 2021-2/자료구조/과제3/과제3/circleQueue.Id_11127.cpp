#include <stdio.h>
#include "circleQueue.h"
#define nsize 20

struct cqueue {  //원형큐 구조체
	int front;
	int rear;
	int lastOperation; //마지막 연산인지 체크 해줌 //원소를 넣으면 +1 뺴면 -1
	char queue[nsize];
};

/*문자와 문자를 넣을 원형큐를 전달받고 처리*/
void enqueue(struct cqueue*que, char a) {
	if (que->lastOperation==nsize) { //마지막 연산시 큐가 모두 참
		printf("enqueue불가:원형큐가 꽉 차서 %c 를 넣지 못합니다.\n",a);
	}
	else {
		if(que->lastOperation == 0) {//공간을 모두 비우게 되는 경우
			que->queue[que->rear] = a; //rear==front 이므로 rear 이동 없음
		}
		else {  //마지막 연산도, 비어있는 큐도 아닌 경우
			que->rear = (que->rear + 1) % nsize; //rear이동 
			que->queue[que->rear] = a;
		}
		
		printf("enqueue:%c 를 원형큐에 넣습니다.\n",a);
		que->lastOperation++;
	}

}
/*원형큐에서 원소 뺌(가장먼저 들어간 원소가 빠짐)*/
void dequeue(struct cqueue*que) {
	if (que->lastOperation == 0) {
		printf("dequeue불가: 원형큐가 비어있습니다.\n");	
	}
	else {
		printf("dequeue:%c 를 원형큐에서 뺍니다.\n", que->queue[que->front]);
		que->queue[que->front] = NULL;
		que->lastOperation--;
		if (que->lastOperation != 0) { //dequeue후, 비어있는 큐가 아닌 경우
			que->front = (que->front + 1) % nsize; //front 이동해 이전 원소를 가장 앞으로 가르킴
		}
	}

}
/*원형큐의 공간 확인*/
void isEmpty(struct cqueue*que) {
	if (que->lastOperation < nsize) {
		printf("원형큐에 공간이 있습니다.\n");
	}
	else {
		printf("원형큐가 꽉 찼습니다.\n");
	}
}
/*원형큐 상태 출력*/
void print(struct cqueue* que) {
	printf("현재 원형큐의 모습입니다.\n");

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
