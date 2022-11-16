#include <stdio.h>
#define SIZE 7

void prims(int (*G_matrix)[SIZE],int *cost,int *count) {
	int visited[SIZE] = { 0 }; //노드 방문 여부 label
	int n, m;
	int u, v; //선택한 edge의 노드

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
					if (visited[n] != 0) 
					{
						min = G_matrix[n][m];
						u = n;
						v = m;
					}
				}
			}
		}
		//방문한적 없는 노드이면 cycle 아님
		if (visited[v] == 0)
		{
			printf("\n%d to %d , weight=%d", u + 1, v + 1, min); //방문한 노드와 가중치 출력
			(*cost) += min;
			(*count)++;
		}

		visited[v] = 1; //방문 후 1로 label
		G_matrix[u][v] = G_matrix[u][v] = 1000; //여러번 min으로 인식 못하도록 바꿔줌

	}
}
