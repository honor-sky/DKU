node* make_Huffman_tree(char arr[]);  
node* makenode(char alphabet, int freq, struct node* left, struct node* right); 
void make_table(node* n, char str[], int len, char* table[]); 
void decode(char* str, node* root); 
node node_arr[alph_num] = { NULL };
int ind = 0;