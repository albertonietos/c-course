#include "source.h"
#include "string.h"


/* Count Substring
 * Count number of occurances of substring <sub> in string <str>,
 * and return the count.
 */
int num_substr(const char *str, const char *sub)
{
    int count = 0;
    char *str_cpy = str;
    printf("str_copy: %s\n", str_cpy);
    char *ptr;
    while (ptr = strstr(str_cpy, sub)) {
        printf("ptr: %s\n", ptr);
        count++;
        str_cpy = ptr + strlen(sub); // move str_cpy pointer to skip the current substring
        printf("str_copy: %s\n", str_cpy);
    }
    return count;
}
