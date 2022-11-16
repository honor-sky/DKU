#include <stdio.h>
#include <stdlib.h>
#include "BFS.h"
#define SIZE 11

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};

// BFS Algorithm
void bfs(struct Graph* graph, int startVertex) {
    struct queue* q =