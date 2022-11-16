/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32200327
*	    Student name : 김경민
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
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
 * you need to implement FCFS, RR, SPN, HRRN, MLFQ scheduler.
 */

/* Process Info Struct 
 *프로세스 번호
 * 프로세스 도착시간
 * 프로세스 서비스 시간
 * 프로세스 수행시간(지금까지 수행했던 시간)
*/ 
typedef struct process {
	int number = 0;    // process number (just input sequence)
	int arrive_t = 0;  // arrival time
	int service_t = 0; // service time
	int process_t = 0; // sum of processing time

}process;

// amount of process
static int p_num;



// sort 
int  arrival_sort(const void* a, const void* b) {
	if ((*(process*)a).arrive_t >= (*(process*)b).arrive_t)
		return 1;
	else if ((*(process*)a).arrive_t < (*(process*)b).arrive_t)
		return -1;
	else
		return 0;
	
}


void FCFS(process *proc_arr,int p) { //프로세스 정보 리스트로 줌(번호, 도착시간, 서비스 시간) //1초는 그냥 for문 한 번 도는 것으로 수행
	init(proc_arr, p);
	p_num = p;

	// process_sort
	qsort(proc_arr, p_num, sizeof(process), arrival_sort);

	//구현
	int i, j,k;
	int total = 0;
	for (i = 0; i < p_num; i++) {
		printf("%d번 프로세스: ", proc_arr[i].number);

		//이미 지난 시간 total만큼 ㅁ
		for (j = 0; j < total; j++) {
			printf("ㅁ");
		}
		//도착시간이 total 보다 큰 경우
		if (total < proc_arr[i].arrive_t) {
			for (k = 0; k < proc_arr[i].arrive_t - total; k++) {
				printf("ㅁ");
			}
		}
		//processing
		for (j = 0; j < proc_arr[i].service_t; j++) {
			printf("■");
			total++; 
		}
		printf("\n");
		
	}
	
}

void SPN(process *proc_arr, int p) {
	init(proc_arr, p);
	p_num = p;

	// process_sort
	qsort(proc_arr, p_num, sizeof(process), arrival_sort);

	int i, j, k;
	int total = proc_arr[0].arrive_t;
	//int count = 0;
	for (i = 0; i < p_num; i++) {
		
		//구현
		//int min_service_pNum = 0;
		int min_service_t = 99999;
		int min_idx = 0;
		int count = 0;

		for (j = 0; j < p_num; j++) {
			//flag = 0;
			if (proc_arr[j].process_t != proc_arr[j].service_t) { //수행 다 안 끝난거면

				if (total >= proc_arr[j].arrive_t) { //minimum 보다 작으면 
					count++; 
					if (min_service_t > proc_arr[j].service_t) {

						min_service_t = proc_arr[j].service_t;
						//min_service_pNum = proc_arr[j].number;
						min_idx = j;
					}
				}
			}
		}

		
		if (count == 0) {
			printf("%d번 프로세스: ", proc_arr[i].number);

			for (j = 0; j < total; j++) {
				printf("ㅁ");
			}

			for (k = 0; k < proc_arr[i].arrive_t - total+1; k++) {
				printf("ㅁ");
				total++;
			}

			//processing
			for (j = 0; j < proc_arr[i].service_t; j++) {
				printf("■");
				total++;
				(proc_arr[i].process_t)++;
			}
			
		}
		else {
			printf("%d번 프로세스: ", proc_arr[min_idx].number);

			for (j = 0; j < total; j++) {
				printf("ㅁ");
			}

			if (total < proc_arr[i].arrive_t) {
				for (k = 0; k < proc_arr[i].arrive_t - total; k++) {
					printf("ㅁ");
					total++;
				}
			}
			//processing
			for (j = 0; j < min_service_t; j++) {
				printf("■");
				total++;
				(proc_arr[min_idx].process_t)++;
			}
			
		}
printf("\n");


	}
}


void RR(process *proc_arr, int p, int Q) {
	init(proc_arr, p);
	int p_num = p;

	int i, j;
	int time_s = Q;
	int total = 0;

	// process_sort
	qsort(proc_arr, p_num, sizeof(process), arrival_sort);

	//sum of service time
	int sum = 0;
	int sum_proc = 0;
	for (i = 0; i < p_num; i++) {
		sum += proc_arr[i].service_t;
	}
	sum_proc = sum;

	int list[100];
	int list_cnt = 0;
	int ready_cnt = 0;
	int readyQ[100];

	//구현
	//모든 서비스가 다 수행 되면 종료
	while (sum_proc != 0) {
		int flag = 0;

		//레디큐
		//도착시간==total 인거 있는지 확인
		for (j = 0; j < p_num; j++) {
			if (proc_arr[j].arrive_t == total) {
		
				//////인덱스 저장해서 먼저 저장
				readyQ[ready_cnt] = proc_arr[j].number;
				ready_cnt++;
				proc_arr[j].process_t++;
				flag = 1;
			}
		}

		for (j = 0; j < p_num; j++) {
			if (proc_arr[j].arrive_t < total) {
				if (((proc_arr[j].process_t) != (proc_arr[j].service_t)) && (list[list_cnt - 1] == proc_arr[j].number)) { //이전 수행큐에서 수행 했으면
					readyQ[ready_cnt] = proc_arr[j].number;
					ready_cnt++;
					proc_arr[j].process_t++; 
					flag = 1;
				}

			}
		}

		if (flag == 0 && ready_cnt < list_cnt) { //레디큐에 아무것도 없어서 수행할 것도 없는 공백일 경우
			for (i = 0; i < (proc_arr[i].arrive_t - total); i++) {
				readyQ[ready_cnt] = 0;
				ready_cnt++;
			}
		}

		//수행큐
		//if (flag == 1) {
		for (i = 0; i < time_s; i++) {
			list[list_cnt] = readyQ[list_cnt];

			total++;
			sum_proc--;
		}
		list_cnt++;
			
		//}
		//else {
			//for (i = 0; i < (proc_arr[i].arrive_t - total); i++) {
			//	list[list_cnt] = 0;
				
			//	total++;
			//}
			//list_cnt++;
		//}

	}

	print_simulation(list, list_cnt,p);
}


void HRRN(process *proc_arr, int p) {

	init(proc_arr, p);
	int p_num = p;

	int i, j;
	int total = 0;
	

	int list[100]; //수행 리스트
	int list_cnt = 0;
	int p_count=0;

	int sum = 0;
	int sum_proc = 0;
	for (i = 0; i < p_num; i++) {
		sum += proc_arr[i].service_t;
	}
	sum_proc = sum;


	// process_sort
	qsort(proc_arr, p_num, sizeof(process), arrival_sort);

	//구현
	while (sum_proc != 0) {
		int flag = 0;
		int max = 0;
		int idx = 0;

		for (i = 0; i < p_num; i++) {
			if (proc_arr[i].arrive_t <= total) {
				if ((proc_arr[i].process_t) != (proc_arr[i].service_t)) {
					if (max < (((total - proc_arr[i].arrive_t) + proc_arr[i].service_t) / proc_arr[i].service_t)) {

						max = (((total - proc_arr[i].arrive_t) + proc_arr[i].service_t) / proc_arr[i].service_t);
						idx = i;
						flag = 1;
					}
				}
				
			}
		}
		
		//수행큐
		if (flag == 1) {
			for (i = 0; i < proc_arr[idx].service_t; i++) {
				list[list_cnt] = proc_arr[idx].number;

				(proc_arr[idx].process_t)++;
				list_cnt++;
				total++;
				sum_proc--;
				
			}
			p_count++;
		}
		else {
			for (i = 0; i < (proc_arr[p_count].arrive_t - total); i++) {
				list[list_cnt] = 0;
				list_cnt++;
				total++;
			}
			p_count++;
		}

	}
	printf("\n");
	print_simulation(list, list_cnt,p);
}

/*
void MLFQ(process proc_arr[], int p) {
 
}*/


void print_simulation(int list[],int list_cnt,int p_num) { //프로세스 번호와 서비스 시간을 받아 화면에 출력
	
	int i,j;
	for (i = 0; i < p_num; i++) {
		printf("%d번 프로세스: ", i+1);

		for (j = 0; j < list_cnt; j++) {
			if (list[j] == i + 1) {
				printf("■");
			}
			else if (list[j] == 0) {
				printf("ㅁ");
			}
			else {
				printf("ㅁ");
			}
		}
		printf("\n");
	}
}

void init(process *proc_arr, int p) {
	int i;
	for (i = 0; i < p_num; i++) {
		proc_arr[i].process_t = 0;
	}

}