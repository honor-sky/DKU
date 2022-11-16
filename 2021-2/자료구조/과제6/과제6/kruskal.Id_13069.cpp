#include <stdio.h>
#include "kruskal.h"
#define SIZE 7

void kruskal(int(*G_matrix)[SIZE], int* cost, int* count) {
	int visited[SIZE] = { 0 }; //��� �湮 ���� label
	int parent[SIZE] = { 0 };  //cycle ���� Ȯ���ϱ� ���� label
	int n, m;
	int u, v; //������ edge�� ���
	int pu, pv; //������ ����� �θ���
	int x; //cycle ����

	visited[0] = 1; //ù��� �湮
	while (*count < SIZE - 1)
	{
		int min = 100; //min�� ������ ������ ����
		for (n = 0; n < SIZE; n++)
		{
			for (m = 0; m < SIZE; m++)
			{
				if ((G_matrix[n][m] != 0) && (G_matrix[n][m] < min))
				{
						min = G_matrix[n][m];
						u = n;
						v = m;
				}
			}
		}
	
		pu = find_parent(u, parent);
		pv = find_parent(v, parent);
		
		x = is_cyclic(pu, pv, parent); // cycle Ȯ��
		if (x == 1)
		{
			printf("\n%d to %d , weight=%d", u+1,v+1, min);
			(*count)++;
			(*cost) += min;
		}
		G_matrix[u][v] = G_matrix[v][u] = 999;
	}
}
//���õ� ����� ���� ��� ã��
int find_parent(int a, int parent[])
{
	while (parent[a] != 0)
		a = parent[a];
	return a;
}

// cycel ���� Ȯ��
int is_cyclic(int a, int b, int parent[])
{
	if (a != b) //a==b �̸� cycle!
	{
		parent[b] = a;
	
		return 1;
	}
	return 0;
}