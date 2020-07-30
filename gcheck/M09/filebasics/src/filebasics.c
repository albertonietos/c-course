#include "filebasics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print give file <filename> to the standard output stream.
 * Return number of characters printed, -1 if file opening fails.
 */
int print_file_and_count(const char *filename)
{
    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    unsigned int count = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Print buffer
        printf("%s", buffer);
        count += strlen(buffer);
    }

    fclose(file);
    return count;
}

/* Compare two files. The function should return the first lines that differ
 * in the two files, concatenated together, separated by four dashes, on
 * different lines. If the files are equal, NULL is returned. 
 * Function stops immediately, if either one of the files end and returns NULL.
 * You can assume that lines are not longer than 1000 characters.
 */
char *difference(const char *file1, const char *file2)
{
    // Open files for reading
    FILE *file_1 = fopen(file1, "r");
    if (!file_1) {
        return NULL;
    }
    FILE *file_2 = fopen(file2, "r");
    if (!file_2) {
        return NULL;
    }

    // Initialize buffers with space for 1000 characters
    char buffer_1[1000];
    char buffer_2[1000];

    const char *middle = "----\n";

    while (fgets(buffer_1, sizeof(buffer_1), file_1) != NULL && fgets(buffer_2, sizeof(buffer_2), file_2) != NULL) {
        // Check if strings are different
        if (strcmp(buffer_1, buffer_2) != 0) {
            // Allocate memory for output
            char *output = malloc(strlen(buffer_1) + strlen(middle) + strlen(buffer_2) + 1);
            if (output == NULL) {
                return NULL;
            }

            // Copy to output
            char *ptr = output;
            strcpy(ptr, buffer_1);
            ptr += strlen(buffer_1);

            strcpy(ptr, middle);
            ptr += strlen(middle);

            strcpy(ptr, buffer_2);

            return output;
        }
    }
    // If it arrives here, there are no differences between the files
    return NULL;
    
}


