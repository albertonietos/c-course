#include "source.h"
#include "ctype.h"
#include "string.h"

char *my_toupper(char *dest, const char *src)
{
    //char *dest_copy = dest;
    while (*src != '\0') {
        if (*src == '?') {
            *dest = '!';
            dest++;
        } else if (*src == '.') {
            *dest = '!';
            dest++;
            *dest = '!';
            dest++;
            *dest = '!';
            dest++;
        } else {
            *dest = toupper(*src);
            dest++;
        }
        src++;
    }
    *dest = '\0';

    //*dest = dest_copy;
    return dest;
}