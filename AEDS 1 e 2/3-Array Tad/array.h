#pragma once

typedef struct Array {
    int *A;
    int size;
    int length;
} array_t;

array_t new_array(int size);
void print_array(array_t *arr);
void append(array_t *arr, int n);
void resize(array_t *arr);