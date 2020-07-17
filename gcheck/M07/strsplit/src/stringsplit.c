#include "stringsplit.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Split string by another string, return split parts + NULL in outputay.
 *
 * Parameters: 
 *  str: the string to split
 *  split: the string to split str with
 *
 * Returns:
 *  A dynamically reserved output array of dynamically reserved string parts.
 *
 * For example called with "Test string split" and " ",
 * returns ["Test", "string", "split", NULL].
 * Or called with "Another - test" and " - ",
 * returns ["Another", "test", NULL].
 */

char** split_string(const char *str, const char* split) {
    // Find number of tokens in the string (minimum is 1)
    unsigned int nbr_tokens = 1;
    unsigned int len_separator = strlen(split);
    const char *ptr = strstr(str, split);

    while (ptr) {
        // Advance to next token 
        ptr = strstr(ptr + len_separator, split);
        nbr_tokens++;
    }

    // Add one extra to the length for NULL value at the end
    nbr_tokens++;

    // Allocation of memory for output outputay
    char **output = malloc(nbr_tokens * sizeof(char *));
    if (output == NULL) {
        free(output);
        return NULL;
    }

    // Add NULL at the end
    output[nbr_tokens - 1] = NULL;

    // Set pointer back to start
    ptr = str;

    // Set new pointer
    const char *new_ptr = strstr(str, split);

    for (unsigned int i = 0; i < (nbr_tokens - 1); i++) {
        // Initialize length of token
        unsigned len = 0;

        // Get length of token to be added
        if (new_ptr == NULL) {
            // Last token
            while (ptr[len]) {
                len++;
            }
        } else {
            len = new_ptr - ptr;
        }

        // Allocate memory for this token
        output[i] = malloc((len + 1) * sizeof(char));
        if (output[i] == NULL) {
            for (unsigned int j = 0; j < i; j++) {
                free(output[j]);
            }
            free(output);
        }

        // Copy the token
        memcpy(output[i], ptr, len);

        // Assign NULL terminator to the last character
        output[i][len] = '\0';

        // If there are more tokens left, update ptr & new_ptr to the next ones
        if (new_ptr != NULL) {
            ptr = new_ptr + len_separator;
            new_ptr = strstr(ptr, split);
        }
    }
    return output;
}

void print_split_string(char **split_string) {
    for (int i = 0; split_string[i] != NULL; i++) {
        printf("%s\n", split_string[i]);
    }
}

void free_split_string(char **split_string) {
    char **string = split_string;
    // Free each element of the array
    while (*string) {
        free(*string);
        string++;
    }
    // Free the array
    free(split_string);
}



