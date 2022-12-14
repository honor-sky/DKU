/*#include <stdio.h>
#include <string.h>
#include "tree.h"
#define NSIZE 20

struct tree_node {
	struct tree_node* left;
	struct tree_node* right;
	char data;
};


int main() {

	char ex1[] = "(7-1)/2";
	char ex2[] = "2*4*4/6+7+1*3";
	char ex3[] = "2/8+(4*3)-3";
	char ex4[] = "6*(1+1)-1/2";
	char ex5[] = "3+4+6+5+5";

	char postfix1[NSIZE];
	char postfix2[NSIZE];
	char postfix3[NSIZE];
	char postfix4[NSIZE];
	char postfix5[NSIZE];

	toPostfix(ex1, postfix1);
	toPostfix(ex2, postfix2);
	toPostfix(ex3, postfix3);
	toPostfix(ex4, postfix4);
	toPostfix(ex5, postfix5);
	
	tree_node * etree1 = MakeTree(postfix1);
	tree_node* etree2 = MakeTree(postfix2);
	tree_node* etree3 = MakeTree(postfix3);
	tree_node* etree4 = MakeTree(postfix4);
	tree_node* etree5 = MakeTree(postfix5);

	Infix_order(etree1);
	printf("  -> 중위 순회\n");
	prefix_order(etree1);
	printf("  -> 전위 순회\n");
	postfix_order(etree1);
	printf("  -> 후위 순회\n");
	level_order(etree1);
	printf("  -> 레벨 순회\n\n");

	Infix_order(etree2);
	printf("  -> 중위 순회\n");
	prefix_order(etree2);
	printf("  -> 전위 순회\n");
	postfix_order(etree2);
	printf("  -> 후위 순회\n");
	level_order(etree2);
	printf("  -> 레벨 순회\n\n");

	Infix_order(etree3);
	printf("  -> 중위 순회\n");
	prefix_order(etree3);
	printf("  -> 전위 순회\n");
	postfix_order(etree3);
	printf("  -> 후위 순회\n");
	level_order(etree3);
	printf("  -> 레벨 순회\n\n");

	Infix_order(etree4);
	printf("  -> 중위 순회\n");
	prefix_order(etree4);
	printf("  -> 전위 순회\n");
	postfix_order(etree4);
	printf("  -> 후위 순회\n");
	level_order(etree4);
	printf("  -> 레벨 순회\n\n");

	Infix_order(etree5);
	printf("  -> 중위 순회\n");
	prefix_order(etree5);
	printf("  -> 전위 순회\n");
	postfix_order(etree5);
	printf("  -> 후위 순회\n");
	level_order(etree5);
	printf("  -> 레벨 순회\n\n");

	
	return 0;
}*/                                                                                                                     ev->next = short_node->next;
    }

    short_node->next = 0;
    return short_node;
}

node* buildHuffmanTree()
{
    while (1)
    {
        node* first = findSmallest();   // 빈도수 제일 낮은 것을 뽑는다.
        node* second = findSmallest();

        if (second == 0)   // 마지막에 트리만 뽑힌다.
        {
            return first;
        }

        node* newOne = (node*)malloc(sizeof(node));
        newOne->next = 0;
        newOne->left = first;
        newOne->right = second;
        newOne->cnt = first->cnt + second->cnt;

        addToSLL(newOne);   // 트리 전체를 구성원으로 넣는다.
    }

}


void showAll(node* head)
{
    node* temp = head;
    while (temp != 0)
    {
        printf("%c : %d\n", temp->v, temp->cnt);
        temp = temp->next;
    }
}

void showCode()
{
    for (int i = top - 1; i >= 0; i--)
    {
        printf("%d", stack[i]);
    }
    printf("\n");
}

void inorderTraversal(node* cur)
{
    if (cur == 0)
    {
        pop();
        return;
    }
    push(0);
    inorderTraversal(cur->left);
    if (cur->left == 0 && cur->right == 0)
    {
        printf("%c : ", cur->v);
        showCode();
    }
    push(1);
    inorderTraversal(cur->right);
    pop();
}
*/