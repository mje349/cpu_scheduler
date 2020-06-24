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


// Handle Process Arrival PP (Priority Based)

struct PCB handle_process_arrival_pp(
        struct PCB ready_queue[QUEUEMAX],
        int *queue_cnt,
        struct PCB current_process,
        struct PCB new_process,
        int timestamp)
{
    //TODO
    return current_process;
}
