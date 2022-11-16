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

