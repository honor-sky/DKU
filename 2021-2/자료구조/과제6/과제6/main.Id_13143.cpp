struct queue;
struct node;
struct Graph;
void bfs(struct Graph* graph, int startVertex);
struct node* createNode(int);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);

                                                                                                                                                                        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex+1);

        struct node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
//DFS Alforithm
void dfs(struct Graph* graph, int vertex) {
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex+1);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

//??