#include "source.h"

#include <stdio.h>
#include <math.h>

void simple_multiply(void)
{
    int a, b, ret;
    ret = scanf("%d %d", &a, &b);
    if (ret > 0) {
        int c = a * b;
        printf("%d * %d = %d\n", a, b, c);
    }
}


void simple_math(void)
{
    float a, b;
    char op;
    int ret;
    ret = scanf("%f %s %f", &a, &op, &b);
    if (ret > 0) {
        float c = 0;
        switch (op)
        {
        case '+':
            c = a + b;
            printf("%.1f\n", c);
            break;

        case '-':
            c = a - b;
            printf("%.1f\n", c);
            break;
        
        case '*':
            c = a * b;
            printf("%.1f\n", c);
            break;

        case '/':
            c = a / b;
            printf("%.1f\n", c);
            break;

        default:
            printf("ERR\n");
            break;
        }
        
    }
}




