#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define alph_num 26

//트리 노드
typedef struct node
{
	char alphabet;  //알파벳
	int freq;//빈도수
	struct node* left; //왼쪽 자식 노드
	struct node* right; //오른쪽 자식 노드
}node;



//새 노드 생성
node* makenode(char alphabet, int freq, struct node* left, struct node* right)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->alphabet = alphabet;
	new_node->freq = freq;
	new_node->left = left;
	new_node->right = right;
	return new_node;
}

//허프만 코드 트리 생성(압축하고자 하는 문자열)
node* make_Huffman_tree(char arr[])
{
	int i = 0;
	int j;
	int temp_n = 0;
	int min = 0;  //제일 빈도수가 작은 index
	int min2 = 0; //두 번째로 빈도수가 작은 index
	int fre[alph_num] = { 0 };  //알파벳(A~Z) 빈도 수
	int check[alph_num] = { 0 };  //합쳐졌는지 확인(합쳐져서 살펴 볼 필요가 없으면 -1)
	node* tree[alph_num] = { NULL };  //비교할 노드 배열
	node* new_node; //새 노드

	while (arr[i] != NULL)
	{
		//빈도수 구하기
		fre[arr[i] - 'A']++;
		i++;
	}
	for (int i = 0; i < alph_num; i++)
	{
		//알파벳이 존재하면
		if (fre[i] != 0)
		{
			node_arr[ind] = *makenode(i + 'A', fre[i], NULL, NULL);
			tree[ind++] = makenode(i + 'A', fre[i], NULL, NULL); //노드 생성
		}
	}
	for (i = 0; i < ind - 1; i++)
	{
		//가장 작은 수 찾기
		j = 0;
		while (check[j] == -1)	j++; //합쳐진 노드를 제외한 배열 중 가장 앞 index
		min = j; //우선 제일 작다고 가정

		for (j = min; j < ind - 1; j++) //모든 배열을 검사
			if (check[j] != -1) //이미 합쳐진 노드가 아니면(검사해볼 필요가 있으면)
				if (tree[min]->freq > tree[j]->freq)
					//min인덱스 빈도수 보다 빈도수가 작은 경우
					min = j;

		//두번째로 작은 수 찾기
		j = 0;
		while (check[j] == -1 || j == min) j++;
		//합쳐진 노드와 최소 노드 제외한 배열 중 가장 앞 index
		min2 = j;  //두번째로 작다고 가정

		for (j = min2; j < ind; j++)
			if (check[j] != -1) //이미 합쳐진 노드가 아니면
				if (tree[min2]->freq > tree[j]->freq)
					//min2인덱스 빈도수 보다 빈도수가 작은 경우
					if (j != min) //가장 작은 index가 아닌 경우
						min2 = j;

		tree[min] = makenode(NULL, tree[min]->freq + tree[min2]->freq, tree[min], tree[min2]);
		//min과 min2인덱스의 빈도수를 합친 빈도수로 새 노드 생성
		//새로 만든 노드를 min인덱스 자리에 넣는다.

		check[min2] = -1;
		//min2인덱스는 min인덱스 자리의 노드에 합쳐졌으므로 check[min2]<-=1
	}
	return tree[min]; //만들어진 트리의 루트 노드 반환
}

//알파벳 별 가변길이 코드 배열 생성
//(트리 루트 노드,가변 길이 코드 문자열,문자열에 들어갈 위치, 저장 될 배열)
//void make_table(node* n, char str[], int len, char* table[])
//{
//	if (n->left == NULL && n->right == NULL) //n이 단노드인 경우
//	{
//		str[len] = '\0'; //문장의 끝을 str끝에 넣어주고
//						 //단 노드의 알파벳을 확인하여 table의 적절한 위치에 str문자열을 넣는다.
//		strcpy(table[(n->alphabet) - 'A'], str);
//	}
//	else //단 노드가 아닌 경우
//	{
//		if (n->left != NULL) //왼쪽 자식이 있는 경우
//		{
//			str[len] = '0'; //문자열에 0 삽입
//			make_table(n->left, str, len + 1, table);
//			//재귀호출(문자열에 들어갈 위치에 +1)
//		}
//		if (n->right != NULL) //오른쪽 자식이 있는 경우
//		{
//			str[len] = '1'; //문자열에 1 삽입
//			make_table(n->right, str, len + 1, table);
//			//재귀호출(문자열에 들어갈 위치에 +1)
//		}
//	}
//}

//디코드함수(디코딩 하고 싶은 문자열, 트리 루트 노드)
void decode(char* str, node* root)
{
	int i = 0;
	node* j = root;
	while (str[i] != '\0') //문자의 끝이 아닌 경우
	{
		if (str[i] == '0') //문자가 0인 경우
			j = j->left; //왼쪽 자식으로 이동
		else if (str[i] == '1') //문자가 1인 경우
			j = j->right; //오른쪽 자식으로 이동
		if (j->left == NULL && j->right == NULL