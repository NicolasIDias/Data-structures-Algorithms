#include <stdio.h>
#include "array.h"

int main()
{

    array_t arr = new_array(10);

    for (int i = 0; i < 5; i++)
    {
        arr.A[i] = i;
        arr.length++;
    }

    print_array(&arr);
    append(&arr, 100);
    print_array(&arr);

    return 0;
}