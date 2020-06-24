// Author: Montana Esguerra
// Date: 6/23/20
// Description: TestBed for cpu scheduler
//

#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

int main(int argc, char* argv[])
{
    struct PCB test;
    set_zero_pcb(&test);
    read_pcb(test);

    return 0;
}
