#include <stdio.h>

unsigned int arraylen(const char *array)
{
    int end = 0;
    while (array[end] != 0) {
        end++;
    }
    return end;
}

void countchars(const char *array, unsigned int *counts)
{
    
}




