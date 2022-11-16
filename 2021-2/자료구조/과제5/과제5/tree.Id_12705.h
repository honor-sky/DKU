#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include "tree.h"
#define NSIZE 20

struct tree_node {
	struct tree_node* left;
	struct tree_node* right;
	char data;
};
typedef struct QueueType {

	tree_node* data[NSIZE];
	int front, rear;

}QueueType;

void QueueInit(QueueType* q) {

	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {

	return (q->front == q->rear);
}

int is_full(QueueType* q) {

	return ((q->rear 