#include "source.h"
#include "ctype.h"
#include "string.h"

char *my_toupper(char *dest, const char *src)
{
    char *dest_copy = dest;
    while (*src != '\0') {
        if (*src == '?') {
            *dest_copy = '!';
            dest_copy++;
        } else if (*src == '.') {
            *dest_copy = '!';
            dest_copy++;
            *dest_copy = '!';
            dest_copy++;
            *dest_copy = '!';
            dest_copy++;
        } else {
            *dest_copy = toupper(*src);
            dest_copy++;
        }
        src++;
    }
    *dest_copy = '\0';

    *dest = dest_copy;
    return dest;
}