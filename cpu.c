// Author: Montana Esguerra
// Date: 6/3/2020
// Description: CPU Scheduler

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

void hello()
{
    printf("Hello from cpu.c!\n");
}

//Reads the contents of PCB
void read_pcb(struct PCB pcb)
{
    printf("process id: %d\n", pcb.process_id);
    printf("arrival_timestamp: %d\n", pcb.arrival_timestamp);
    printf("total_bursttime: %d\n", pcb.total_bursttime);
    printf("execution start time: %d\n", pcb.execution_starttime);
    printf("execution end time: %d\n", pcb.execution_endtime);
    printf("remaining burst time: %d\n", pcb.remaining_bursttime);
    printf("process priority: %d\n", pcb.process_priority);
}

//Zeroes a PCB
void set_zero_pcb(struct PCB *pcb)
{
    pcb->process_id = 0;
    pcb->arrival_timestamp = 0;
    pcb->total_bursttime = 0;
    pcb->execution_starttime = 0;
    pcb->execution_endtime = 0;
    pcb->remaining_bursttime = 0;
    pcb->process_priority = 0;
}

//Checks if a pcb is the null pcb
//by adding all values. If the returned value is non zero,
//then the pcb is not the null pcb.

int is_null_pcb(struct PCB *pcb)
{
    int result = 0;

    result = pcb->process_id + pcb->arrival_timestamp + pcb->total_bursttime + pcb->execution_starttime + pcb->execution_endtime + pcb->remaining_bursttime + pcb->process_priority;

    return result;
}


// Handle Process Arrival PP (Priority Based)

struct PCB handle_process_arrival_pp(
        struct PCB ready_queue[QUEUEMAX],
        int *queue_cnt,
        struct PCB current_process,
        struct PCB new_process,
        int timestamp)
{
    //TODO
    //There is no currently running process i.e. third argument is the null pcb
    //Then return the newly arriving process
    int is_null = current_process.process_id + current_process.arrival_timestamp + current_process.total_bursttime + current_process.execution_starttime 
        + current_process.execution_endtime + current_process.remaining_bursttime + current_process.process_priority;

    //if this evaluates true: then the current process is the null pcb
    if (!is_null)
    {
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;

        return new_process;
    }

    return current_process;
}
