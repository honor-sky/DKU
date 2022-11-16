#include <stdio.h>
#include "circleQueue.h"
#define nsize 20

//struct cqueue {
//	int front;
//	int rear;
//	int lastOperation;
//	char queue[nsize];
//};
//
//int main(void) {
//
//	struct cqueue que;
//  /*초기화*/
//	que.front = 0;
//	que.rear = 0;
//	que.lastOperation = 0;
//
//	isEmpty(&que);
//	enqueue(&que, 'A');
//	enqueue(&que, 'B');
//	enqueue(&que, 'C');
//	print(&que);
//	printf("\n");
//
//	dequeue(&que);
//	dequeue(&que);
//	print(&que);
//	printf("\n");
//
//	dequeue(&que);
//	print(&que);
//	printf("\n");
//
//	dequeue(&que);
//
//
//	return 0;
//}