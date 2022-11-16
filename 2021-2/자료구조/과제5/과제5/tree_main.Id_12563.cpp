struct tree_node;
typedef struct QueueType;
void QueueInit(QueueType* q);
int is_empty(QueueType* q);
int is_full(QueueType* q);
void enqueue(QueueType* q, tree_node* item);
tree_node* dequeue(QueueType* q);
tree_node* MakeTreeNode(void);
void SetData(tree_node* bt, int data);
void MakeRightSubTree(tree_node* main, tree_node* sub);
void MakeLeftSubTree(tree_node* main, tree_node* sub);
tree_node* MakeTree(char postfix[]);
void Infix_order(tree_node* node);
void prefix_order(tree_node* node);
void postfix_order(tree_node* node);
void lev