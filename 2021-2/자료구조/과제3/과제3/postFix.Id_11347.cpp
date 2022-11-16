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
		p