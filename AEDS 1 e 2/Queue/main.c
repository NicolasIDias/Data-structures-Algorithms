#include <stdio.h>
#include "queue.h"

int main(){

    queue_t fila1 = new_queue(10);


    for(int i=0;i<6;i++){
        fila1.A[i] = i;
        fila1.length++;
    }

    print_queue(&fila1);

    delete_queue(&fila1);
    return 0;
}