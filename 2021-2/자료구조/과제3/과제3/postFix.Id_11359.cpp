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
			break;

		case ')':
			while (stack[top] != '(') { // ( ���������� ���ÿ��� ���
				printf("%c", stack[top]);
				stack[top] = NULL;
				top--;
			}
			stack[top] = NULL; // ( ���ֱ�
			top--;
			wait--;
			break;

		case '+':
		case '-':
			if (wait > 0) { //(�� �ֱ� ������ ������ �����ڰ� ���ÿ� ��
				top++;
				stack[top] = infix[i];
				break;
			}
			/*� �������̵� ���ÿ� �ִٸ� ���� �������� ��*/
			if (stack[top] == '*' || stack[top] == '/'|| stack[top] == '+'||stack[top] == '-') { 
				printf("%c", stack[top]);
				top--;
			}
			top++;
			stack[top] = infix[i];
			break;

		case '/':
		case '*':
			if (stack[top] == '*' || stack[top]=='/') {
				printf("%c", stack[top]);
				top--;
			}
			top++;
			stack[top] = infix[i];
			break;

		default: //�ǿ����� ���
			printf("%c", infix[i]);
		}

	}

	for (int j = top; j >= 0; j--) {  //�������� ���ÿ� ���� �͵� ��� ���
		printf("%c", stack[j]);
	}
	printf("\n");

	freeArray(stack);
}