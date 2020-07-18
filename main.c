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
    struct PCB current_process;
    struct PCB new_process;
    struct PCB null_pcb;
    int time_stamp = 2;

    set_pcb(&current_process, 1, 1, 8, 1, 9, 8, 0);
    set_pcb(&new_process, 2, 2, 6, 0, 0, 6, 0);
    set_pcb(&null_pcb, 0, 0, 0, 0, 0, 0, 0);

    printf("Current Process: \n");
    display_pcb(&current_process);
    printf("\n");

    printf("Ready_Queue[0]: \n");
    display_pcb(&ready_queue[0]);
    printf("\n");

    struct PCB result = handle_process_arrival_srtp(ready_queue, &queue_cnt, current_process, new_process, time_stamp);

    display_pcb(&result);

    /*
    struct PCB result = handle_process_arrival_pp(ready_queue, &queue_cnt, current_process, new_process, time_stamp);
    printf("RESULT: \n");
    display_pcb(&result);
    printf("\n");

    printf("\n\n");
    printf("*queue_cnt: %d\n", queue_cnt);
    printf("queue_cnt: %d\n", queue_cnt);

    if(!enqueue_pcb(ready_queue, &queue_cnt, &current_process))
            printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &new_process))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");
    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");

    if(!enqueue_pcb(ready_queue, &queue_cnt, &null_pcb))
        printf("Ready Queue is full\n");


    for(int i = 0; i < queue_cnt; ++i)
    {
        display_pcb(&ready_queue[i]);
        printf("\n==================\n");
    }
*/

    return 0;
}
