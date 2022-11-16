#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nsize 5

char* array(int n) { //배열 동적할당
	char* arr;
	arr = (char*)malloc(sizeof(char) * n);
	return arr;
}

void freeArray(char* arr) {  //동적할당 반환
	free(arr);
}

void postfix(char* infix) {

	char* stack = array(nsize); //스택 동적 생성
	int top = -1; //스택의 top 가르킴
	int wait = 0; // (가 몇개 있는지 알려줌

	for (int i = 0; i<strlen(infix); i++) {
		switch (infix[i]){
		case '(':
			top++;
			stack[top]= infix[i];
			wait++;
			break;

		case ')':
			while (stack[top] != '(') { // ( 만날때까지 스택에서 출력
				printf("%c", stack[top]);
				stack[top] = NULL;
				top--;
			}
			stack[top] = NULL; // ( 없애기
			top--;
			wait--;
			break;

		case '+':
		case '-':
			if (wait > 0) { //(가 있기 때문에 무조건 연산자가 스택에 들어감
				top++;
				stack[top] = infix[i];
				break;
			}
			/*어떤 연산자이든 스택에 있다면 먼저 출력해줘야 함*/
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

		default: //피연산자 출력
			printf("%c", infix[i]);
		}

	}

	for (int j = top; j >= 0; j--) {  //마지막에 스택에 남은 것들 모두 출력
		printf("%c", stack[j]);
	}
	printf("\n");

	freeArray(stack);
}