#include "stringsplit.h"

#include <stdio.h>
#include <string.h>


/* Split string by another string, return split parts + NULL in array.
 *
 * Parameters: 
 *  str: the string to split
 *  split: the string to split str with
 *
 * Returns:
 *  A dynamically reserved array of dynamically reserved string parts.
 *
 * For example called with "Test string split" and " ",
 * returns ["Test", "string", "split", NULL].
 * Or called with "Another - test" and " - ",
 * returns ["Another", "test", NULL].
 */

char** split_string(const char *str, const char* split) {
    char **token;
    unsigned int i = 0;

    // Get the first token
    token[i] = strtok(str, split);

    // Look through the other ones
    while (token[i] != NULL) {
        token[i] = strtok(NULL, split);
        i++;
    }

    return token;
}

void print_split_string(char **split_string) {
    for (int i = 0; split_string[i] != NULL; i++) {
        printf("%s\n", split_string[i]);
    }
}

void free_split_string(char **split_string) {
    
}



