tree:tree.o tree_main.o
	gcc -o tree tree.o tree_main.o
tree.o: tree.o tree.h
	gcc -c tree.c -o tree.o
tree_main.o: tree_main.c
	gcc -c tree_main.c -o tree_main.o
clean:
	rm -f  tree*o

                                                                                                                                                                                                                                                                                                                                      temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = cur;
}


void createVertex(char _v)
{
    node* newOne = (node*)malloc(sizeof(node));
    newOne->v = _v;
    newOne->cnt = 1;
    newOne->left = newOne->right = newOne->next = 0;

    addToSLL(newOne);
}

node* findVertex(char v)
{
    node* temp = head;
    while (temp != 0)
    {
        if (temp->v == v)
        {
            return temp;
        }
        temp = temp->next;
    }
    return 0;
}

void cntCharacterNum(char* _buf)
{
    char v;
    for (int i = 0; i < 99; i++)
    {
        if (_buf[i] == '\0')
        {
            return;
        }
        v = _buf[i];
        if (findVertex(v) == 0)
        {
            createVertex(v);
        }
        else
        {
            node* find = findVertex(v);
            find->cnt += 1;
        }
    }
}

node* findSmallest()
{

    int short_num = INT_MAX;
    node* short_node = head;

    if (head == 0)
    {
        return 0;
    }

    node* temp = head;
    while (temp != 0)
    {
        if (temp->cnt < short_num)
        {
            short_node = temp;
            short_num = temp->cnt;
        }
        temp = temp->next;
    }

    if (short_node == head)
    {
        head = head->next;
    }
    else
    {
        node* prev = head;
        while (prev->next != short_node