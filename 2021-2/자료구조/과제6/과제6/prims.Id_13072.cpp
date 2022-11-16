#include <stdio.h>
#define SIZE 7

void prims(int (*G_matrix)[SIZE],int *cost,int *count) {
	int visited[SIZE] = { 0 }; //��� �湮 ���� label
	int n, m;
	int u, v; //������ edge�� ���

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
					if (visited[n] != 0) 
					{
						min = G_matrix[n][m];
						u = n;
						v = m;
					}
				}
			}
		}
		//�湮���� ���� ����̸� cycle �ƴ�
		if (visited[v] == 0)
		{
			printf("\n%d to %d , weight=%d", u + 1, v + 1, min); //�湮�� ���� ����ġ ���
			(*cost) += min;
			(*count)++;
		}

		visited[v] = 1; //�湮 �� 1�� label
		G_matrix[u][v] = G_matrix[u][v] = 1000; //������ min���� �ν� ���ϵ��� �ٲ���

	}
}
