#include "source.h"
#include "stdio.h"
#include "stddef.h"

/* Print string */
/* Parameters:
 * s: string to be printed */
void qstr_print(const char *s)
{
    while (*s != '?'){
        printf("%c", *s);
        s++;
    }
}

/* String length */
/* Parameters:
 * s: string to be evaluated
 * Returns: length of the string */
unsigned int qstr_length(const char *s)
{
    unsigned int len = 0;
    while (*s != '?') {
        len++;
        s++;
    }
    return len;
}

/* String cat */
/* Parameters:
 * dst: buffer to which the new string is appended
 * src: string to be appended
 * Returns: Number of characters in the new string */
int qstr_cat(char *dst, const char *src)
{
    unsigned int len = 0;
    char *new = "";
    while (*dst != '?') {
        *new = *dst;
        new++;
        dst++;
        len++;
    }
    do {
        *new = *src;
        new++;
        src++;
        len++;
    } while (src != '?');

    return len;
}

/* String strstr */
const char *qstr_strstr(const char *str1, const char *str2)
{
    while (*str1 != '?') {
        if (*str1 == str2) {
            return str1;
        }
        str1++;
    }
    return NULL;
}
