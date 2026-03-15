#include <stdlib.h>
#include <stdio.h>
#include "array.h"

array_t new_array(int size)
{
    array_t arr;
    arr.size = size;
    arr.A = malloc(sizeof(int) * size);
    arr.length = 0;
    return arr;
}

void append(array_t *arr, int n)
{
    if (arr->length == arr->size)
    {
        resize(arr);
    }
    arr->A[arr->length++] = n;
}

void insert(array_t *arr, int n; int index)
{
    
}

void resize(array_t *arr)
{
    int size = arr->size * 2;
    int *tmp = realloc(arr->A, sizeof(int) * size);
    arr->A = tmp;
    arr->size = size;
}

void print_array(array_t *arr)
{
    printf("[");
    for (int i = 0; i < arr->length; i++)
    {
        if (i == arr->length - 1)
        {
            printf("%d", arr->A[i]);
        }
        else
        {
            printf("%d, ", arr->A[i]);
        }
    }
    printf("]");
    printf("\n");
}
