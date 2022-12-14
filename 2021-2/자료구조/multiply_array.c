#include<stdlib.h>

#include"common.h"

int **array( int rows, int cols){  //2차원 자료구조 동적생성
	int* vec;
	int **arr;
	int i;

	arr = (int **) malloc( sizeof( int ) * rows );
	for( i=0; i<rows; i++)
	   arr[i] = (int *) malloc( sizeof(int)*cols );

	return arr;
}


int *vector( int rows){ //1차원 자료구조 동적생성
	int *vec;

	vec = (int *) malloc( sizeof( int ) * rows ); 

	return vec;
}

void freeArray( int **arr, int rows, int cols ){
	int r, c;
	for( r=0; r<rows; r++)
	    freeVector( arr[r] );

	free(arr);
}

void freeVector( int *vec ){
    free( vec );
}

void printArray( int **arr, int rows, int cols, char *msg){
	int r, c;

	printf("%s\n", msg );
	for(r=0; r<rows; r++){
		for(c=0; c<col