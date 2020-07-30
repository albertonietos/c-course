#include "hexread.h"
#include <stdio.h>
#include <stdlib.h>

/* Prints the given file as hexdump, at most 16 numbers per line.
 * <filename> parameter is the name of the file.
 * 
 * Returns the number of characters read
 */
int file_to_hex(const char *filename)
{
    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    // Read the 1st element of file and store it in ptr
    unsigned int count = 0;
    unsigned char *ptr = malloc(sizeof(char));
    size_t nmemb = 1;
    size_t n = fread(ptr, sizeof(unsigned char), nmemb, file);
    count++;

    while (n == nmemb) {
        printf("%02x ", *ptr);
        
        // Jump line after 16 hex values
        if (count % 16 == 0){
            printf("\n");
        }
        count++;

        // Read next element in file
        n = fread(ptr, sizeof(unsigned char), nmemb, file);
    }

    free(ptr);
    return 0;
}
