#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size)
{
    for (unsigned int row = size; row > 0; row--) {
        for (unsigned int col = 0; col < size; col++) {
            if (row -1 > col){
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}
