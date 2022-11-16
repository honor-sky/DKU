#include <stdio.h>
#include "prims.h"
#include "kruskal.h"
#include "BFS.h"

int main() {
	
	int cost = 0;
	int count = 0;
	

	int G_matrix[7][7] = {  //����ġ������� //�Է±׷���
		{0,28,0,0,0,10,0},  //adj_matrix[0][0~6] //��ξ����� NULL�� ó��
		{28,0,16,0,0,0,14},
		{0,16,0,12,0,0,0},
		{0,0,12,0,22,0,18},
		{0,0,0,22,0,25,24},
		{10,0,0,0,25,0,0},
		{0,14,0,18,24,0,0} //�����ķ� ����°� ������
	};

	prims(G_matrix,&cost,&count);
	//kruskal(G_matrix, &cost, &count);

	printf("\nminimum cost is %d", cost); //�ּ� ��� ���
	printf("\nnumber of node is %d", count); //��� ���� ���
	printf("\nnumber of edge is %d", count-1); //���� ���� ���

	printf("\n\nBFS\n");

	/*BFS*/
	struct Graph* graph = createGraph(11);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 0);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 5);
	addEdge(graph, 2, 1);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 0);
	addEdge(graph, 3, 5);
	addEdge(graph, 4, 1);
	addEdge(graph, 4, 2);
	addEdge(graph, 4, 6);
	addEdge(graph, 4, 8);
	addEdge(graph, 5, 3);
	addEdge(graph, 5, 6);
	addEdge(graph, 5, 8);
	addEdge(graph, 6, 4);
	addEdge(graph, 6, 5);
	addEdge(graph, 7, 8);
	addEdge(graph, 8, 4);
	addEdge(graph, 8, 5);
	addEdge(graph, 8, 7);
	addEdge(graph, 9, 10);
	addEdge(graph, 10, 9);

	bfs(graph, 0);

	
	return 0;