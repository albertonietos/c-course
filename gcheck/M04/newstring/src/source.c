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
    while (*src != '?') {
        *dst = *src;
        src++; dst++;
        len++;
    }
    *dst = '?';
    return len;
}

/* String strstr */
const char *qstr_strstr(const char *str1, const char *str2)
{
    const char *ptr;

    while (*str1 != '?') {
        while (*str1 != *str2 && *str1 != '?') {
            // Keep looking
            str1++;
        }
        if (*str1 == '?') {
            // If ending of str1, finish
            return NULL;
        } else {
            // If not, it could be the location we are looking for
            ptr = str1;
            while (*str1 == *str2 && *str1 != '?' && *str2 != '?') {
                str1++;
                str2++;
            }
            // If loop ended because str2 is done, we have found a match
            if (*str2 == '?') {
                return ptr;
            }
            // If loop ended becasue str1 is done, it did not find a match
            if (*str1 == '?') {
                return NULL;
            }
            ptr++;
        }
    }
}