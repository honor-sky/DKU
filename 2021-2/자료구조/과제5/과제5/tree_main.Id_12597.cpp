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
			brea