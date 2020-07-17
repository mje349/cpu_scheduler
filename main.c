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
    int time_stamp = 2;

    set_pcb(&current_process, 1, 1, 4, 1, 5, 4, 8);
    set_pcb(&new_process, 2, 2, 3, 0, 0, 3, 6);

    printf("Current Process: \n");
    display_pcb(&current_process);
    printf("\n");

    printf("Ready_Queue[0]: \n");
    display_pcb(&ready_queue[0]);
    printf("\n");

    struct PCB result = handle_process_arrival_pp(ready_queue, &queue_cnt, current_process, new_process, time_stamp);
    printf("RESULT: \n");
    display_pcb(&result);
    printf("\n");

    printf("\n\n");
    printf("*queue_cnt: %d\n", queue_cnt);
    printf("queue_cnt: %d\n", queue_cnt);

    return 0;
}
