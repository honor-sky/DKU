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


// 이진 트리 노드 생성 //
tree_node* MakeTreeNode(void)
{
	tree_node* nd = (tree_node*)malloc(sizeof(tree_node));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
// 노드에 데이터를 저장 //
void SetData(tree_node* bt, int data)
{
	bt->data = data;
}

// 전달 받은 'sub' 노드를 'main' 노드의 오른쪽 서브 트리로 연결 //
void MakeRightSubTree(tree_node* main, tree_node* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}
// 전달 받은 'sub' 노드를 'main' 노드의 왼쪽 서브 트리로 연결 //
void MakeLeftSubTree(tree_node* main, tree_node* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}


//트리생성해 삽입
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

	return tree_stack[top]; //root 노드의주소 반환
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);

	else
		printf("%c ", data);
}


/*순회 알고리즘*/
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



char* array(int n) { //배열 동적할당
	char* arr;
	arr = (char*)malloc(sizeof(char) * n);
	return arr;
}

void freeArray(char* arr) {  //동적할당 반환
	free(arr);
}

//infix 표기법을 전달받아 postfix 방식으로 변환
void toPostfix(char* infix, char* postfix) {

	char* stack = array(NSIZE); //스택 동적 생성
	int top = -1; //스택의 top 가르킴
	int wait = 0; // (가 몇개 있는지 알려줌
	int count = 0; //profix의 인덱스 알려줌

	for (int i = 0; i < strlen(infix); i++) {
		switch (infix[i]) {
		case '(':
			top++;
			stack[top] = infix[i];
			wait++;
			break;

		case ')':
			while (stack[top] != '(') { // ( 만날때까지 스택에서 출력
				//postfix[count] = stack[top];
				printf("%c", infix[i]);
				count++;
				stack[top] = NULL;
				top--;
			}
			
			stack[top] = NULL; // ( 없애기
			top--;
			wait--;
			break;

		case '+':
		case '-':
			if (wait > 0) { //(가 있기 때문에 무조건 연산자가 스택에 들어감
				top++;
				stack[top] = infix[i];
				break;
			}
			/*어떤 연산자이든 스택에 있다면 먼저 출력해줘야 함*/
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

		default: //피연산자 출력
			//postfix[count] = stack[top];
			printf("%c", infix[i]);
			count++;
		}
	}

	for (int j = top; j >= 0; j--) {  //마지막에 스택에 남은 것들 모두 출력
		printf("%c", stack[j]);
		//postfix[count] = stack[j];
		count++;
	}

}