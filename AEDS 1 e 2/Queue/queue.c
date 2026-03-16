#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue_t new_queue(int size)
{
    queue_t queue;
    queue.size = size;
    queue.size = 0;
    queue.A = malloc(sizeof(int) * size);

    return queue;
}

void delete_queue(queue_t *queue)
{
    if (queue != NULL)
    {
        free(queue->A);
        queue->A = NULL;
    }
    queue->size = 0;
    queue->length = 0;
}

void print_queue(queue_t *queue)
{
    if (queue == NULL)
    {
        printf("[Erro]: Fila vazia");
    }
    else
    {
        printf("[");
        for (int i = 0; i < queue->length; i++)
        {
            if (i == queue->length - 1)
            {
                printf("%d", queue->A[i]);
            }
            else
            {
                printf("%d, ", queue->A[i]);
            }
        }
        printf("]");
        printf("\n");
    }
}