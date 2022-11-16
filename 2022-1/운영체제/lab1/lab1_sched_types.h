/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 32200327
*	    Student name :±è°æ¹Î
*
*   lab1_sched_types.h :
*       - lab1 header file.
*       - must contains scueduler algorithm function's declations.
*
*/

#ifndef _LAB1_HEADER_H
#define _LAB1_HEADER_H


/*
 * You need to Declare functions in  here
 */

typedef struct process;
void FCFS(process *proc_arr, int p);
int arrival_sort(const void* a, const void* b);
void print_simulation(int list[], int list_cnt, int p_num);
void SPN(process *proc_arr, int p);
void RR(process *proc_arr, int p, int Q);
void HRRN(process *proc_arr, int p);
void init(process *proc_arr, int p);



#endif /* LAB1_HEADER_H*/