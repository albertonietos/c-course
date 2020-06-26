#include "source.h"
#include "ctype.h"
#include "string.h"

char *my_toupper(char *dest, const char *src)
{
	for (int i = 0; *(src + i) != '\0'; i++) {
        if (*(src + i) == '?') {
            *(dest + i) = '!';
        } else if (*(src + i) == '.') {
            *(dest + i) = '!';
            dest++;
            *(dest + i) = '!';
            dest++;
            *(dest + i) = '!';
        } else {
            *(dest + i) = toupper(*(src + i));
        }
    }
    dest[strlen(dest)-1] = '\0';
    return dest;
}