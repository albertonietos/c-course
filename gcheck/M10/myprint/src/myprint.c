#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int myprint(const char *str, ...) {
    int count = 0;
    va_list args;
    va_start(args, str);

    for (unsigned int i = 0; i < strlen(str); i++) {
        // If character is ampersan -> print integer
        if (str[i] != '&') {
            fputc(str[i], stdout);
        } else {
            printf("%d", va_arg(args, int));
            count++;
        }
    }
    va_end(args);

    return count;
}