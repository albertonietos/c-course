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
    while (*dst != '?') {
        dst++;
        len++;
    }

    while (*src != '?') {
        *dst = *src;
        dst++;
        src++;
        len++;
    }
    *dst = '?';
    return len;
}

/* String strstr */
const char *qstr_strstr(const char *str1, const char *str2)
{
    const char *ptr;
    int i = 0; // index for str1
    int j = 0; // index for str2
    int store_i = 0;

    while (*(str1 + i) != '?') {
        while (*(str1 + i) != *(str2 + 0) && *(str1 + i) != '?') {
            // If there is no match, keep looking
            i++;
        }
        if (*(str1 + i) == '?') {
            // If we arrived at the end of str1, finish without sucess
            return NULL;
        } else {
            // If we found a location where *str1==*str2, it could be the location we are looking for
            ptr = str1 + i;
            store_i = i;
            // Check that the following characters match as well
            while (*(str1 + i) == *(str2 + j) && *(str1 + i) != '?' && *(str2 + j) != '?') {
                i++;
                j++;
            }
            
            if (*(str2 + j) == '?') { // If loop ended because str2 is done, we have found a match
                return ptr;
            } else if (*(str1 + i) == '?') { // If loop ended becasue str1 is done, it did not find a match
                return NULL;
            }
            i = store_i + 1; // Start next iteration after index investigated
            j = 0; //Reset index for str2
        }
    }
    return NULL;
}