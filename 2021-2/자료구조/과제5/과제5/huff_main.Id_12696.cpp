/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char v;
    int cnt;
    node* next;
    node* left;
    node* right;
};



void initStack() {
    int stack[100];
    int top = -1;
}


void push(int n)
{
    top += 1;
    stack[top] = n;
}

int pop()
{
    int result = stack[top];
    top -= 1;
    return result;
}

void addToSLL(node* cur, node* head)
{
    if (head == 0)
    {
        head = cur;
        return;
    }

    node* temp = head;
    while (temp->next != 0)
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
    newOne->left