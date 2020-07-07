#include "book.h"
#include <stdlib.h>
#include <string.h>

int init_book(struct book *p_book, const char *p_id, const char *p_title, const char *p_author, struct date release)
{  
    // Allocate memory to pointers: p_title, p_author, and copy the values in the right location
    p_book->title = malloc(strlen(p_title) + 1);
    if (p_book->title == NULL) {
        free(p_book);
        return 0;
    }
    strcpy(p_book->title, p_title);

    p_book->author = malloc(strlen(p_author) + 1);
    if (p_book->author == NULL) {
        free(p_book);
        return 0; 
    }
    strcpy(p_book->author, p_author);
    
    // Since id is a char array, we have to iterate
    for (int i = 0; i < 10; i++) {
        p_book->id[i] = p_id[i];
    }
    p_book->release_date = release;

    if (strlen(p_id) <= 9) {
        return 1;
    } else {
        return 0;
    }
}

struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book)
{   
    // Increase size of the collection by one, and reserve space for final NULL member
    struct book *newcollection = realloc(collection, sizeof(struct book) * (size + 1));
    if (newcollection == NULL) {
        return NULL; // allocating new memmory did not work
    }

    // Check that initialization succeeds
    if (!init_book(&new_book, new_book.id, new_book.title, new_book.author, new_book.release_date )) {
        free(newcollection);
        return NULL;
    }

    newcollection[size].author = new_book.author;
    newcollection[size].release_date = new_book.release_date;
    newcollection[size].title = new_book.title;

    for (int j = 0; j < 10; j++) {
        newcollection[size].id[j] = new_book.id[j];
    }

    return newcollection;
}