#include "source.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ascii_chart(char min, char max)
{
    for (int i = min; i <= max; i++) {
        printf("%3d 0x%x ", i, i);
        if ( !isprint(i) ) {
            printf("?");
        } else {
            printf("%c", i);
        }
        if ((i + 1 - min) % 4 == 0 && i != min) {
            printf("\n");
        } else {
            printf("\t");
        }
    }
}
