/*
 * Author: Montana Esguerra
 * Filename: main.c
 * Description: Test bed for cpu scheduler
 */

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

int main( int argc, char* argv[])
{
    struct PCB ready_queue[QUEUEMAX];// empty ready queue
    int queue_cnt = 0;
    struct PCB process1;
    struct PCB process2;
    struct PCB process3;
    int timestamp = 2;
    int time_quantum = 10;

    set_pcb(&process1, 1, 22, 8, 0, 0, 8, 0);
    set_pcb(&process2, 2, 21, 8, 0, 0, 8, 0);
    set_pcb(&process3, 3, 23, 8, 0, 0., 8, 0);

    enqueue_pcb(ready_queue, &queue_cnt, &process1);
    enqueue_pcb(ready_queue, &queue_cnt, &process2);
    enqueue_pcb(ready_queue, &queue_cnt, &process3);

    for(int i = 0; i < queue_cnt; ++i)
    {
        display_pcb(&ready_queue[i]);
        printf("\n===================\n");
    }

    printf("\n AFTER\n\n");

    struct PCB result = handle_process_completion_rr(ready_queue, &queue_cnt, timestamp, time_quantum);

    for(int i = 0; i < queue_cnt; ++i)
    {
        display_pcb(&ready_queue[i]);
        printf("\n===================\n");
    }

    printf("\n EARLIEST TIME ARRIVAL\n");
    display_pcb(&result);





    return 0;
}
