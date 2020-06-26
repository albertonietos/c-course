#include "source.h"
#include "ctype.h"
#include "string.h"

char *my_toupper(char *dest, const char *src)
{
    for (size_t i = 0; i < strlen(src); i++) {
        if (*src == '?') {
            *dest = '!';
            dest++;
        } else if (*src == '.') {
            *dest = '!';
            dest++;
            *dest = '!';
            dest++;
            *dest = '!';
        } else {
            *dest = toupper(*(src + i));
            dest++;
        }
        src++;
    }
    *dest = '\0';
    return dest;
}