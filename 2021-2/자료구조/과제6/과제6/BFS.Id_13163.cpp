#include <stdio.h>
#include "prims.h"
#include "kruskal.h"
#include "BFS.h"

int main() {
	
	int cost = 0;
	int count = 0;
	

	int G_matrix[7][7] = {  //가중치인접행렬 //입력그래프
		{0,28,0,0,0,10,0},  //adj_matrix[0][0~6] //경로없음은 NULL로 처리
		{28,0,16,0,0,0,14},
		{0,16,0,12,0,0,0},
		{0,0,12,0,22,0,18},
		{0,0,0,22,0,25,24},
		{10,0,0,0,25,0,0},
		{0,14,0,18,24,0,0} //희소행렬로 만드는게 나을듯
	};

	prims(G_matrix,&cost,&count);
	//kruskal(G_matrix, &cost, &count);

	printf("\nminimum cost is %d", cost); //최소 비용 출력
	printf("\nnumber of node is %d", count); //노드 개수 출력
	printf("\nnumber of edge is %d", count-1); //엣지 개수 출력

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
}                                                                                                                                                               tices = vertices;

    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

//노드 생성
struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 엣지 추가
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// 큐 생성
struct queue* createQueue() {
    struct queue* q = (struct queue* )malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// 큐 비었는지 확인
int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

//enqueue
void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->fr