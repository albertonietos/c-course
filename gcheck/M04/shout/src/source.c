#include "source.h"
#include "ctype.h"

char *my_toupper(char *dest, const char *src)
{
	for (int i = 0; *(src + i) != '\0'; i++) {
        if (*(src + i) == '?') {
            *(dest + i) = '!';
        } else if (*(src + i) == '.') {
            *(dest + i) = '!!!';
        } else {
            *(dest + i) = toupper(*(src + i));
        }
    }
    return dest;
}