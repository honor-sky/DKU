/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32200327
*	    Student name : ����
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
	printf("������ ���μ��� ������ �Է��ϼ���: ");
	scanf_s("%d", &p_num);
	pArr = (process*)malloc(sizeof(process) * p_num); //�Է¹��� ������ŭ ���μ��� ����ü �迭�� ���� ����

	// initiate process information
	int i;
	for (i = 0; i < p_num; i++) {
		// input arrival time and service time of each process 
		pArr[i].number = i + 1; // process number
		printf("%d�� ���μ��� �����ð��� �Է��Ͻÿ�: ",i+1);
		scanf_s("%d", &pArr[i].arrive_t);
		printf("%d�� ���μ��� ���񽺽ð��� �Է��Ͻÿ�: ", i + 1);
		scanf_s("%d", &pArr[i].service_t);
		pArr[i].process_t = 0;

	}
	printf("\n");
	
	printf("FCFS\n");
	FCFS(pArr, p_num); //�迭�� ù��Ҹ� ����Ű�� ������ ����
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