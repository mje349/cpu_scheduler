// Author: Montana Esguerra
// Date: 6/23/20
// Description: TestBed for cpu scheduler
//

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

int main(int argc, char* argv[])
{
    //struct PCB ready_queue[QUEUEMAX];
    struct PCB current_process, new_process;//, returned_pcb;
    //int timestamp = 2;
    //int queue_cnt = 0;

    setup_pcb(&current_process,1,1,4,1,5,4,8);
    setup_pcb(&new_process,2,2,3,0,0,3,6);

    read_pcb(current_process);
    printf("============================\n\n");
    read_pcb(new_process);

    //returned_pcb = handle_process_arrival_pp(ready_queue, &queue_cnt, current_process, new_process, timestamp);

    return 0;
}
