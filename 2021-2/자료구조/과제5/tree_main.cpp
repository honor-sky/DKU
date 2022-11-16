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
	printf("  -> ���� ��ȸ\n");
	prefix_order(etree1);
	printf("  -> ���� ��ȸ\n");
	postfix_order(etree1);
	printf("  -> ���� ��ȸ\n");
	level_order(etree1);
	printf("  -> ���� ��ȸ\n\n");

	Infix_order(etree2);
	printf("  -> ���� ��ȸ\n");
	prefix_order(etree2);
	printf("  -> ���� ��ȸ\n");
	postfix_order(etree2);
	printf("  -> ���� ��ȸ\n");
	level_order(etree2);
	printf("  -> ���� ��ȸ\n\n");

	Infix_order(etree3);
	printf("  -> ���� ��ȸ\n");
	prefix_order(etree3);
	printf("  -> ���� ��ȸ\n");
	postfix_order(etree3);
	printf("  -> ���� ��ȸ\n");
	level_order(etree3);
	printf("  -> ���� ��ȸ\n\n");

	Infix_order(etree4);
	printf("  -> ���� ��ȸ\n");
	prefix_order(etree4);
	printf("  -> ���� ��ȸ\n");
	postfix_order(etree4);
	printf("  -> ���� ��ȸ\n");
	level_order(etree4);
	printf("  -> ���� ��ȸ\n\n");

	Infix_order(etree5);
	printf("  -> ���� ��ȸ\n");
	prefix_order(etree5);
	printf("  -> ���� ��ȸ\n");
	postfix_order(etree5);
	printf("  -> ���� ��ȸ\n");
	level_order(etree5);
	printf("  -> ���� ��ȸ\n\n");

	
	return 0;
}*/