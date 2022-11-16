/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32200327
*	    Student name : 김경민
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm test code.
*
*/

//#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
//#include <sys/time.h>
#include <string.h>
//#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
//#include <pthread.h>
//#include <asm/unistd.h>

#include "lab1_sched_types.h"

/*
 * you need to implement scheduler simlator test code.
 *
 */

typedef struct process {
	int number = 0;    // process number (just input sequence)
	int arrive_t = 0;  // arrival time
	int service_t = 0; // service time
	int process_t = 0; // sum of processing time

}process;

int main(int argc, char* argv[]) {

	process *pArr;
	int p_num;
	// input process amount 
	printf("생성할 프로세스 개수를 입력하세요: ");
	scanf_s("%d", &p_num);
	pArr = (process*)malloc(sizeof(process) * p_num); //입력받은 갯수만큼 프로세스 구조체 배열을 동적 생성

	// initiate process information
	int i;
	for (i = 0; i < p_num; i++) {
		// input arrival time and service time of each process 
		pArr[i].number = i + 1; // process number
		printf("%d번 프로세스 도착시간을 입력하시오: ",i+1);
		scanf_s("%d", &pArr[i].arrive_t);
		printf("%d번 프로세스 서비스시간을 입력하시오: ", i + 1);
		scanf_s("%d", &pArr[i].service_t);
		pArr[i].process_t = 0;

	}
	printf("\n");
	
	printf("FCFS\n");
	FCFS(pArr, p_num); //배열의 첫요소를 가르키는 변수를 전달
	printf("\n");

	printf("SPN\n");
	SPN(pArr, p_num);
	printf("\n");
	
	printf("RR\n");
	RR(pArr, p_num,1);
	printf("\n");
	
	printf("HRRN\n");
	HRRN(pArr, p_num);
	printf("\n");


	free(pArr);

	//call schduling algorithm

	


}