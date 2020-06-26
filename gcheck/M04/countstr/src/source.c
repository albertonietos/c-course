#include "source.h"
#include "string.h"


/* Count Substring
 * Count number of occurances of substring <sub> in string <str>,
 * and return the count.
 */
int num_substr(const char *str, const char *sub)
{
    int count = 0;
    const char *str_cpy = str;
    char *ptr;
    while (ptr = strstr(str_cpy, sub)) {
        count++;
        str_cpy = ptr + strlen(sub); // move str_cpy pointer to skip the current substring
    }
    return count;
}
