#include <stdio.h>
#include "kruskal.h"
#define SIZE 7

void kruskal(int(*G_matrix)[SIZE], int* cost, int* count) {
	int visited[SIZE] = { 0 }; //노드 방문 여부 label
	int parent[SIZE] = { 0 };  //cycle 여부 확인하기 위한 label
	int n, m;
	int u, v; //선택한 edge의 노드
	int pu, pv; //선택한 노드의 부모노드
	int x; //cycle 여부

	visited[0] = 1; //첫노드 방문
	while (*count < SIZE - 1)
	{
		int min = 100; //min을 임의의 값으로 설정
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
		
		x = is_cyclic(pu, pv, parent); // cycle 확인
		if (x == 1)
		{
			printf("\n%d to %d , weight=%d", u+1,v+1, min);
			(*count)++;
			(*cost) += min;
		}
		G_matrix[u][v] = G_matrix[v][u] = 999;
	}
}
//선택된 노드의 이전 노드 찾기
int find_parent(int a, int parent[])
{
	while (parent[a] != 0)
		a = parent[a];
	return a;
}

// cycel 여부 확인
int is_cyclic(int a, int b, int parent[])
{
	if (a != b) //a==b 이면 cycle!
	{
		parent[b] = a;
	
		return 1;
	}
	return 0;
}