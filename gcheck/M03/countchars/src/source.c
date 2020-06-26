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
    unsigned int ch = 0;
    while (array[ch] != 0) {
        printf("int: %d, ", ch);
        printf("array[ch]: %c \n", array[ch]);
        // Add one to current character's count
        unsigned int char_index = array[ch];
        counts[char_index]++;
        ch++; // Next index in array
    }
}




