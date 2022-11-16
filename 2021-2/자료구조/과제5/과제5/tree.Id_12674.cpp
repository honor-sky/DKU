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
	new_node->left = left;
	new_node->right = right;
	return new_node;
}

//������ �ڵ� Ʈ�� ����(�����ϰ��� �ϴ� ���ڿ�)
node* make_Huffman_tree(char arr[])
{
	int i = 0;
	int j;
	int temp_n = 0;
	int min = 0;  //���� �󵵼��� ���� index
	int min2 = 0; //�� ��°�� �󵵼��� ���� index
	int fre[alph_num] = { 0 };  //���ĺ�(A~Z) �� ��
	int check[alph_num] = { 0 };  //���������� Ȯ��(�������� ���� �� �ʿ䰡 ������ -1)
	node* tree[alph_num] = { NULL };  //���� ��� �迭
	node* new_node; //�� ���

	while (arr[i] != NULL)
	{
		//�󵵼� ���ϱ�
		fre[arr[i] - 'A']++;
		i++;
	}
	for (int i = 0; i < alph_num; i++)
	{
		//���ĺ��� �����ϸ�
		if (fre[i] != 0)
		{
			node_arr[ind] = *makenode(i + 'A', fre[i], NULL, NULL);
			tree[ind++] = makenode(i + 'A', fre[i], NULL, NULL); //��� ����
		}
	}
	for (i = 0; i < ind - 1; i++)
	{
		//���� ���� �� ã��
		j = 0;
		while (check[j] == -1)	j++; //������ ��带 ������ �迭 �� ���� �� index
		min = j; //�켱 ���� �۴ٰ� ����

		for (j = min; j < ind - 1; j++) //��� �迭�� �˻�
			if (check[j] != -1) //�̹� ������ ��尡 �ƴϸ�(�˻��غ� �ʿ䰡 ������)
				if (tree[min]->freq > tree[j]->freq)
					//min�ε��� �󵵼� ���� �󵵼��� ���� ���
					min = j;

		//�ι�°�� ���� �� ã��
		j = 0;
		while (check[j] == -1 || j == min) j++;
		//������ ���� �ּ� ��� ������ �迭 �� ���� �� index
		min2 = j;  //�ι�°�� �۴ٰ� ����

		for (j = min2; j < ind; j++)
			if (check[j] != -1) //�̹� ������ ��尡 �ƴϸ�
				if (tree[min2]->freq > tree[j]->freq)
					//min2�ε��� �󵵼� ���� �󵵼��� ���� ���
					if (j != min) //���� ���� index�� �ƴ� ���
						min2 = j;

		tree[min] = makenode(NULL, tree[min]->freq + tree[min2]->freq, tree[min], tree[min2]);
		//min�� min2�ε����� �󵵼��� ��ģ �󵵼��� �� ��� ����
		//���� ���� ��带 min�ε��� �ڸ��� �ִ´�.

		check[min2] = -1;
		//min2�ε����� min�ε��� �ڸ��� ��忡 ���������Ƿ� check[min2]<-=1
	}
	return tree[min]; //������� Ʈ���� ��Ʈ ��� ��ȯ
}

//���ĺ� �� �������� �ڵ� �迭 ����
//(Ʈ�� ��Ʈ ���,���� ���� �ڵ� ���ڿ�,���ڿ��� �� ��ġ, ���� �� �迭)
//void make_table(node* n, char str[], int len, char* table[])
//{
//	if (n->left == NULL && n->right == NULL) //n�� �ܳ���� ���
//	{
//		str[len] = '\0'; //������ ���� str���� �־��ְ�
//						 //�� ����� ���ĺ��� Ȯ���Ͽ� table�� ������ ��ġ�� str���ڿ��� �ִ´�.
//		strcpy(table[(n->alphabet) - 'A'], str);
//	}
//	else //�� ��尡 �ƴ� ���
//	{
//		if (n->left != NULL) //���� �ڽ��� �ִ� ���
//		{
//			str[len] = '0'; //���ڿ��� 0 ����
//			make_table(n->left, str, len + 1, table);
//			//���ȣ��(���ڿ��� �� ��ġ�� +1)
//		}
//		if (n->right != NULL) //������ �ڽ��� �ִ� ���
//		{
//			str[len] = '1'; //���ڿ��� 1 ����
//			make_table(n->right, str, len + 1, table);
//			//���ȣ��(���ڿ��� �� ��ġ�� +1)
//		}
//	}
//}

//���ڵ��Լ�(���ڵ� �ϰ� ���� ���ڿ�, Ʈ�� ��Ʈ ���)
void decode(char* str, node* root)
{
	int i = 0;
	node* j = root;
	while (str[i] != '\0') //������ ���� �ƴ� ���
	{
		if (str[i] == '0') //���ڰ� 0�� ���
			j = j->left; //���� �ڽ����� �̵�
		else if (str[i] == '1') //���ڰ� 1�� ���
			j = j->right; //������ �ڽ����� �̵�
		if (j->left == NULL && j->right == NULL