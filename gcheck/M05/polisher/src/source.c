#include <stdlib.h>
#include "source.h"

/* Remove C comments from the program stored in memory block <input>.
 * Returns pointer to code after removal of comments.
 * Calling code is responsible of freeing only the memory block returned by
 * the function.
 */
char *delete_comments(char *input)
{
    int len = 1;
    char *copy = input;
    
    //Get input length
    while (*copy) {
        len++;
        copy++;
    }

    //Allocate space for text pointer
    char *text = malloc(len);
    if (text == NULL) {
        return NULL;
    }

    int i = 0;
    copy = input;

    while (*copy) {
        if (*copy == '/' && *(copy+1) == '/') {
            while (*copy && *copy != '\n') {
                copy++;
            }
            copy++;
        }
        else if(*copy == '/' && *(copy + 1) == '*') {
            while (*copy && *copy != '*' && *(copy+1) != '/') {
                copy++;
            }
            copy += 2;
        }
        else {
            text[i] = *copy;
            i++;
            copy++;
        }
    }

    text[i] = 0;
    char * new_text = realloc(text, i + 1);

    if (new_text == NULL) {
        return NULL;
    }

    free(input);
    
    return new_text;
}
