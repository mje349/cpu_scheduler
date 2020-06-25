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

    // if this evaluates true: then the current process is the null pcb
    // This method should then return the PCB of the newly-arriving process
    // inidicating that it is the process to execute next.
    //
    // The PCB of the new process is then modified so that the execution start time
    // is set to the current timestamp, the execution end time is set to the sum of the current
    // timestamp and the total burst time and the remaining burst time is set to the total burst time.
    if (!is_null)
    {
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;

        return new_process;
    }

    // If there is a currently-running process, the method compares the priority of the newly-arriving
    // process with the currently-running process. If the new process has equal or lower priority
    // (note: smaller integers for the priority field in the PCB indicate higher priority), then its
    // PCB is simply added to the ready queue and the return value is the PCB of the curretnly-running
    // process. As the newly-arriving process is added to the ready queue, its execution start time and 
    // execution end time are set to 0, and the remaining burst time is the same as its total burst time.
    if (is_null)//if this evaluates to true - then the current process is not the null_pcb
    {
        //TODO
    }

    return current_process;
}
