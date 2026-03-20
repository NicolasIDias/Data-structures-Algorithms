#include "exercise.h"
#include <stdio.h>

void concat_strings(char *str1, const char *str2)
{
    int i = 0;
    int pos = 0;
    while (str1[pos] != '\0')
    {
        pos++;
    }

    while (str2[i] != '\0')
    {
        str1[pos++] = str2[i++];
    }
    str1[pos] = '\0';
}
