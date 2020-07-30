#include <stdio.h>
#include "filestats.h"
#include <string.h>
#include <ctype.h>

/* Returns the line count in given file
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * The number of lines in file. */
int line_count(const char *filename)
{
    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    unsigned int count = 0;

    // Read one character at a time
    int c = fgetc(file);
    int last_char = 0;

    // If file is empty, there are no lines
    if (c == EOF) {
        return count;
    }

    // While file has not ended
    while (c != EOF) {
        if (c == '\n') {
            count++;
        }
        last_char = c;
        c = fgetc(file);
    }

    // Last character in file should be \n
    if (last_char != '\n') {
        count++;
    }

    // Close file
    fclose(file);

    return count;
}


/* Count the number of words in the file. Word has to include at least one
 * alphabetic character, and words are separated by whitespace.
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * number of words in the file */
int word_count(const char *filename)
{
    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    unsigned int count = 0;

    // Read one character at a time
    int c = fgetc(file);

    // Word marker
    int word = 0;

    // While file has not ended
    while (c != EOF) {
        // If c is alphabetic character 
        // and we have not identified a word yet
        if (isalpha(c) && !word) {
            word = 1;
        } // 
        else if (isspace(c) && word) {
            count++;
            word = 0;  // reset
        }
        c = fgetc(file);
    }

    // If word has not ended (word=1) and EOF is not a space
    if (word && !isspace(c)) {
        count++;
    }

    // Close file
    fclose(file);

    return count;
}
