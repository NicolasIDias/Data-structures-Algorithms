#pragma once
#include "../shared/bool.h"

typedef struct Array
{
    int *A;
    int size;
    int length;
} array_t;

array_t new_array(int size);
void print_array(array_t *arr);
void append(array_t *arr, int n);
void insert_at(array_t *arr, int n, int index);
void remove_at(array_t *arr, int index);
void delete_array(array_t *arr);
void resize(array_t *arr);
bool linear_search(array_t *arr, int target);