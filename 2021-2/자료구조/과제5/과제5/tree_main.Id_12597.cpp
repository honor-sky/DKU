#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nsize 5

char* array(int n) { //�迭 �����Ҵ�
	char* arr;
	arr = (char*)malloc(sizeof(char) * n);
	return arr;
}

void freeArray(char* arr) {  //�����Ҵ� ��ȯ
	free(arr);
}

void postfix(char* infix) {

	char* stack = array(nsize); //���� ���� ����
	int top = -1; //������ top ����Ŵ
	int wait = 0; // (�� � �ִ��� �˷���

	for (int i = 0; i<strlen(infix); i++) {
		switch (infix[i]){
		case '(':
			top++;
			stack[top]= infix[i];
			wait++;
			brea