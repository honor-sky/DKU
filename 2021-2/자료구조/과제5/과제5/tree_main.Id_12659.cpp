#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define alph_num 26

//Ʈ�� ���
typedef struct node
{
	char alphabet;  //���ĺ�
	int freq;//�󵵼�
	struct node* left; //���� �ڽ� ���
	struct node* right; //������ �ڽ� ���
}node;



//�� ��� ����
node* makenode(char alphabet, int freq, struct node* left, struct node* right)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->alphabet = alphabet;
	new_node->freq = freq;
	ne