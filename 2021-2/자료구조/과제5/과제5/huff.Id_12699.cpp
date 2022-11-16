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

	return ((q->rear + 1) % NSIZE == q->front);
}

void enqueue(QueueType* q, tree_node* item) {

	if (is_full(q)) {
		printf("Queue Full");
	}

	q->rear = (q->rear + 1) % NSIZE;
	q->data[q->rear] = item;

}

tree_node* dequeue(QueueType* q) {

	if (is_empty(q))
		printf("Queue Empty");
	q->front = (q->front + 1) % NSIZE;
	return q->data[q->front];
}


// ���� Ʈ�� ��� ���� //
tree_node* MakeTreeNode(void)
{
	tree_node* nd = (tree_node*)malloc(sizeof(tree_node));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
// ��忡 �����͸� ���� //
void SetData(tree_node* bt, int data)
{
	bt->data = data;
}

// ���� ���� 'sub' ��带 'main' ����� ������ ���� Ʈ���� ���� //
void MakeRightSubTree(tree_node* main, tree_node* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}
// ���� ���� 'sub' ��带 'main' ����� ���� ���� Ʈ���� ���� //
void MakeLeftSubTree(tree_node* main, tree_node* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}


//Ʈ�������� ����
tree_node* MakeTree(char postfix[])
{
	tree_node *tree_stack[NSIZE];
	int top = -1;
	tree_node* pnode;

	int i;
	for (i = 0; postfix[i]!='\0'; i++)
	{
		pnode = MakeTreeNode();

		if (isdigit(postfix[i]))
		{
			SetData(pnode, postfix[i]);
		}
		else
		{   
			MakeRightSubTree(pnode, tree_stack[top]);
			top--;
			MakeLeftSubTree(pnode, tree_stack[top]);
			SetData(pnode, postfix[i]);
		}

		top++;
		tree_stack[top]= pnode;
	}

	return tree_stack[top]; //root ������ּ� ��ȯ
}


/*��ȸ �˰���*/
//Infix order
void Infix_order(tree_node *node) {
	if (node != NULL) {
		Infix_order(node->left);
		printf("%c", node->data);
		Infix_order(node->right);
	}
}

// Prefix order
void prefix_order(tree_node *node) {
	if (node != NULL) {

		printf("%c", node->data);
		prefix_order(node->left);
		prefix_order(node->right);
	}
}


// Postfix order
void postfix_order(tree_node *node) {
	if (node != NULL) {
		postfix_order(node->left);
		postfix_order(node->right);
		printf("%c", node->data);
	}
}


// Level order
void level_order(tree_node* node)
{
	QueueType q;

	QueueInit(&q);

	if (node == NULL) return;

	enqueue(&q, node);
	while (!is_empty(&q)) {

		node = dequeue(&q);
		printf("%c", node->data);
		if (node->left)
			enqueue(&q, node->left);
		if (node->right)
			enqueue(&q, node->right);
	}
}


char* array(int n) { //�迭 �����Ҵ�
	char* arr;
	arr = (char*)malloc(sizeof(char) * n);
	return arr;
}

void freeArray(char* arr) {  //�����Ҵ� ��ȯ
	free(arr);
}

//infix ǥ����� ���޹޾� postfix ������� ��ȯ
void toPostfix(char* infix, char* postfix) {

	char* stack = array(NSIZE); //���� ���� ����
	int top = -1; //������ top ����Ŵ
	int wait = 0; // (�� � �ִ��� �˷���
	int