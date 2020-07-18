/*
 * Author: Montana Esguerra
 * Filename: cpu.c
 * Description: Implementation file for cpu scheduler
 */

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

//Helper Functions

void test();
int is_null_pcb(struct PCB *check);

// Enqueue Function for PCB ready_queue
//int enqueue_pcb(struct PCB* ready_queue[], int* queue_cnt, struct PCB* to_enqueue);

void hello()
{
    printf("Hello from oslabs!\n");
    test();
}


//Implementations
void test()
{
    printf("TESTING\n");
}

//Wrapper function for is_null_pcb
//TODO
void is_null(struct PCB *check)
{
    if(is_null_pcb(check))
        printf("IS NULL!\n");

    else
        printf("Not Null\n");
}

//Checks if a PCB is the NULL PCB
//If this returns 1 if NULL PCB, returns 0 if not
int is_null_pcb(struct PCB *check)
{
    if ( check->process_id == 0 && check->arrival_timestamp == 0 && check->total_bursttime == 0 && check->execution_starttime == 0 && check->execution_endtime == 0 && check->remaining_bursttime == 0 && check->process_priority == 0)
        return 1;

    return 0;
}


void set_pcb(struct PCB *to_set, int pid, int ats, int tbt, int est, int eet, int rbt, int pp)
{
    to_set->process_id = pid;
    to_set->arrival_timestamp = ats;
    to_set->total_bursttime = tbt;
    to_set->execution_starttime = est;
    to_set->execution_endtime = eet;
    to_set->remaining_bursttime = rbt;
    to_set->process_priority = pp;
}

void display_pcb(struct PCB *pcb)
{
    printf("Process ID: %d\nArrival Timestamp: %d\nTotal Burst Time: %d\nExecution Start Time: %d\nExecution End Time: %d\nRemaining Burst Time: %d\nProcess Priority: %d\n",
            pcb->process_id, pcb->arrival_timestamp, pcb->total_bursttime, pcb->execution_starttime, pcb->execution_endtime, pcb->remaining_bursttime, pcb->process_priority);
}


//LAB Implementations

// Handle Process Arrival
struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
    // If there is no currently running process
    if(is_null_pcb(&current_process))
    {
        //TODO
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }

    // If the newly arriving process has priority less than or equal to the current process
    if(new_process.process_priority >= current_process.process_priority)
    {
        if((*queue_cnt) < QUEUEMAX)
        {
            new_process.execution_starttime = 0;
            new_process.execution_endtime = 0;
            new_process.remaining_bursttime = new_process.total_bursttime;

            ready_queue[*queue_cnt] = new_process;
            (*queue_cnt)++;
        }

        
        return current_process;
    }

    // If the newly arriving process has higher priority than the current process

    if((*queue_cnt) < QUEUEMAX)
    {
        current_process.execution_endtime = 0;
        current_process.remaining_bursttime = current_process.total_bursttime - 1;

        ready_queue[*queue_cnt] = current_process;
        (*queue_cnt)++;
/*
        printf("SANITY CHECK: =============\n");
        display_pcb(&current_process);
        printf("\n\n\n");
        */
    }


    new_process.execution_starttime = timestamp;
    new_process.execution_endtime = timestamp + new_process.total_bursttime;


    return new_process;

}

// Handle Request Arrival RR
struct PCB handle_process_arrival_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp, int time_quantum)
{
    if(is_null_pcb(&current_process))
    {
         new_process.execution_starttime = timestamp;
         new_process.execution_endtime = timestamp + MIN(new_process.total_bursttime, time_quantum);
         new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }


    new_process.execution_starttime = 0;
    new_process.execution_endtime = 0;
    new_process.remaining_bursttime = new_process.total_bursttime;
    ready_queue[(*queue_cnt)] = new_process;
    (*queue_cnt)++;
    
    return current_process;
}

// Handle Request Arrival SRTP
struct PCB handle_process_arrival_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int time_stamp)
{
    // If there is no currently running process
    if(is_null_pcb(&current_process))
    {
        new_process.execution_starttime = time_stamp;
        new_process.execution_endtime = time_stamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }

    else if(current_process.remaining_bursttime < new_process.remaining_bursttime)
    {
        ready_queue[(*queue_cnt)] = new_process;
        (*queue_cnt)++;
        new_process.execution_starttime = 0;
        new_process.execution_endtime = 0;
        new_process.remaining_bursttime = new_process.total_bursttime;

        return current_process;
    }

    current_process.execution_starttime = 0;
    current_process.execution_endtime = 0;
    current_process.remaining_bursttime = current_process.total_bursttime;
    ready_queue[(*queue_cnt)] = current_process;
    (*queue_cnt)++;

    new_process.execution_starttime = time_stamp;
    new_process.execution_endtime = time_stamp + new_process.total_bursttime;
    new_process.remaining_bursttime = new_process.total_bursttime;
    

    return new_process;
}

// Handle Process Completion PP
struct PCB handle_process_completion_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{
    if((*queue_cnt) == 0)
    {
        struct PCB null_pcb;
        set_pcb(&null_pcb, 0, 0, 0, 0, 0, 0, 0);

        return null_pcb;
    }

    // Locate the index of the highest priority
    int high_index = 0;

    for (int i = 1; i < (*queue_cnt); i++)
    {
        if (ready_queue[high_index].process_priority > ready_queue[i].process_priority)
            high_index = i;
    }

    struct PCB high_priority = ready_queue[high_index];

    // Shift elements up to fill the gap
    for (int i = high_index; i < (*queue_cnt); i++)
    {
        ready_queue[i] = ready_queue[i+1];
    }

    *queue_cnt = *queue_cnt -1;

    high_priority.execution_starttime = timestamp;
    high_priority.execution_endtime = timestamp + high_priority.remaining_bursttime;

    return high_priority; 
}

// Handle Request Completion RR
struct PCB handle_process_completion_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp, int time_quantum)
{
    return ready_queue[0];
}

// Handle Request Completion SRTP
struct PCB handle_process_completion_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{
    return ready_queue[0];
}

// Enqueues a PCB
int enqueue_pcb(struct PCB ready_queue[], int* queue_cnt, struct PCB* to_enqueue)
{
    // Queue is Full - return 0 as error code
    if((*queue_cnt) >= QUEUEMAX)
        return 0;

    ready_queue[(*queue_cnt)] = (*to_enqueue);
    (*queue_cnt)++;

    return 1;
}

