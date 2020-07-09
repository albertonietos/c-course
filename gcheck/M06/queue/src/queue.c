#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int enqueue(struct studentqueue *q, const char *name)
{
    // Allocate memory for new list node
    struct studentqueue *new = malloc(sizeof(struct studentqueue));
    if (new == NULL) {
        free(new);
        return 0;
    }
    // Allocate memory for name
    new->name = malloc(strlen(name) + 1);
    if (new->name == NULL) {
        free(new);
        return 0;
    }

    // Initialize members of allocated structure
    strcpy(new->name, name);
    new->next = NULL;

    // Find the last member of the list
    while (q->next) {
        q = q->next;
    }

    // Modify the next link to point to the newly allocated member
    q->next = new;

    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
    // First name is NULL, so we select the second one
    struct studentqueue *current = q->next;

    // Copy name to buffer
    if (current != NULL) {
        unsigned int len = strlen(current->name);
        // Only copy to buffer if it fits
        if (len < (size - 1)) {
            strncpy(buffer, current->name, size);  
        }
    } else {
        return 0;
    }
    // Move pointer to second element
    q->next = current->next;

    // Free memory allocated for removed item
    free(current->name);
    free(current);

    return 1;
}