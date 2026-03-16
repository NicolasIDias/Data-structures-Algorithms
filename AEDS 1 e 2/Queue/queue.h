#pragma once
#include "../0-shared/bool.h"

typedef struct Queue {
    int *A;
    int size;
    int length;
}queue_t;


queue_t new_queue(int size);
void delete_queue(queue_t *queue);
void print_queue(queue_t *queue);