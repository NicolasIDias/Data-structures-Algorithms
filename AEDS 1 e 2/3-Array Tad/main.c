#include <stdio.h>
#include "array.h"

int main()
{

    array_t arr = new_array(10);

    for (int i = 0; i < 5; i++)
    {
        append(&arr, i);
    }

    print_array(&arr);
    append(&arr, 100);
    insert_at(&arr, 5000, 6);
    print_array(&arr);
    remove_at(&arr, 4);
    remove_at(&arr, 9);
    print_array(&arr);


    delete_array(&arr);
    return 0;
}