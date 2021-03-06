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

//Fills a PCB
void setup_pcb(struct PCB* pcb, int pid, int ats, int tbt, int est, int eet, int rbt, int pp)
{
    pcb->process_id = pid;
    pcb->arrival_timestamp = ats;
    pcb->total_bursttime = tbt;
    pcb->execution_starttime = est;
    pcb->execution_endtime = eet;
    pcb->remaining_bursttime = rbt;
    pcb->process_priority = pp;
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
    // PCB is simply added to the ready queue and the return value is the PCB of the currently-running
    // process. As the newly-arriving process is added to the ready queue, its execution start time and 
    // execution end time are set to 0, and the remaining burst time is the same as its total burst time.
    if (is_null)//if this evaluates to true - then the current process is not the null_pcb
    {
        //TODO
        if(MIN(current_process.process_priority, ready_queue[0].process_priority) == ready_queue[0].process_priority)
        {
            ready_queue[*queue_cnt] = new_process;
            new_process.execution_starttime = 0;
            new_process.execution_endtime = 0;
            new_process.remaining_bursttime = new_process.total_bursttime;
        }

        // If the new process has a higher priority, then the PCB of the currently running process is added to
        // the ready queue and the return value is the PC of the new process. In this case, the PCB of the new
        // process is modified so that the execution start time is set to the current timestamp, the execution
        // end time is set to the sum of the curret timestamp and the total burst time and the remaining 
        // burst time is set to the total burst time. Also, the PCB of the currently running process is added
        // to the ready queue after marking its execution end time as 0, and adjusting its remaining burst
        // time.



        
    }

    return current_process;
}

// This method implements the logic to handle the completion of execution of a process in a Priority-based
// Preemptive Scheduler. Specifically, it takes three inputs: the ready queue (an array of PCB structs),
// the number of items in the ready queue, and the current timestamp
//
// This method determines the process to execute next and returns its PCB
//
struct PCB handle_process_completion_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{

    // If the ready_queue is empty, the method returns the NULLPCB, indicating that there is no process to
    // execute. Otherwise, the method finds the PCB of the process in the ready_queue with the highest
    // priority (smaller integers for the priority field in the PCB mean higher priorities), removes this
    // PCB from the ready_queue and returns it. Before returning the PCB of the next process to execute,
    // it is modified to set the execution start time as the current timestamp and the execution end time
    // as the sum of the current timestamp and the remaining burst time.

    return ready_queue[0];
}
