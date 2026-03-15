#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "../shared/bool.h"

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

void insert_at(array_t *arr, int n, int index)
{
    if (index < 0 || index > arr->length)
    {
        printf("[Erro]: Index fora dos limites. O limite atual e: %d\n", arr->length);
        return;
    }
    if (arr->length == arr->size)
        resize(arr);
    for (int i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = n;
    arr->length++;
}

void remove_at(array_t *arr, int index)
{
    if (index >= arr->length || index < 0)
    {
        printf("[Erro]: Index fora dos limites do array\n");
        return;
    }
    else
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

void resize(array_t *arr)
{
    int size = arr->size * 2;
    int *tmp = realloc(arr->A, sizeof(int) * size);
    if (tmp != NULL)
    {
        arr->A = tmp;
        arr->size = size;
    }
    else
    {
        printf("[Erro]: Memoria insuficiente para dar resize\n");
    }
}

void delete_array(array_t *arr){
    if(arr != NULL){
        free(arr->A);
        arr->A = NULL;
    }
    arr->length = 0;
    arr->size = 0;
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

bool linear_search(array_t *arr, int target){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i] == target) return true;
    }
    return false;
}