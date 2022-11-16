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
tree_node* MakeExpTree(char postfix[])
{
	tree_node *tree_stack[NSIZE];
	int top = -1;
	tree_node* pnode;

	int expLen = strlen(postfix);
	int i;

	//StackInit(&stack);

	for (i = 0; i < expLen; i++)
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

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);

	else
		printf("%c ", data);
}


/*��ȸ �˰���*/
//Infix order
void inOrderTraversal(tree_node *node) {
	if (node != NULL) {
		inOrderTraversal(node->left);
		printf("%c", node->data);
		inOrderTraversal(node->right);
	}
}

// Prefix order
void preOrderTraversal(tree_node *node) {
	if (node != NULL) {
		//visit(node);
		printf("%c", node->data);
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
}


// Postfix order
void postOrderTraversal(tree_node *node) {
	if (node != NULL) {
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		printf("%c", node->data);
		//visit(node);
	}
}


// Level order



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
	int count = 0; //profix�� �ε��� �˷���

	for (int i = 0; i < strlen(infix); i++) {
		switch (infix[i]) {
		case '(':
			top++;
			stack[top] = infix[i];
			wait++;
			break;

		case ')':
			while (stack[top] != '(') { // ( ���������� ���ÿ��� ���
				//postfix[count] = stack[top];
				printf("%c", infix[i]);
				count++;
				stack[top] = NULL;
				top--;
			}
			
			stack[top] = NULL; // ( ���ֱ�
			top--;
			wait--;
			break;

		case '+':
		case '-':
			if (wait > 0) { //(�� �ֱ� ������ ������ �����ڰ� ���ÿ� ��
				top++;
				stack[top] = infix[i];
				break;
			}
			/*� �������̵� ���ÿ� �ִٸ� ���� �������� ��*/
			if (stack[top] == '*' || stack[top] == '/' || stack[top] == '+' || stack[top] == '-') {
				//postfix[count] = stack[top];
				printf("%c", infix[i]);
				count++;
				top--;
			}
			top++;
			stack[top] = infix[i];
			break;

		case '/':
		case '*':
			if (stack[top] == '*' || stack[top] == '/') {
				//postfix[count] = stack[top];
				printf("%c", infix[i]);
				count++;
				top--;
			}
			top++;
			stack[top] = infix[i];
			break;

		default: //�ǿ����� ���
			//postfix[count] = stack[top];
			printf("%c", infix[i]);
			count++;
		}
	}

	for (int j = top; j >= 0; j--) {  //�������� ���ÿ� ���� �͵� ��� ���
		printf("%c", stack[j]);
		//postfix[count] = stack[j];
		count++;
	}

}