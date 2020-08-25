#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Add data structure(s)
struct Person {
    char *name;  // full name, cannot make assumptions about length
    char id[11];  // social security number (11 characters)
    double pension;  // monthly pension (in euros)
};

// Add the needed functions
struct Person *add_person(char *name, char *id, double pension, struct Person *db) {
    // Increase i until we arrive at array member with NULL name
    unsigned int i = 0;
    for (i = 0; db[i].name != NULL; i++);

    // Increase size of the database by one, and reserve space for final NULL member
    struct Person *new_db = realloc(db, sizeof(struct Person) * (i + 2));
    if (new_db == NULL) {
        printf("Memory allocation failed.\n");
        free(new_db);
        return NULL;
    }

    // Initialize person to be added
    struct Person p;
    p.name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(p.name, name);
    strcpy(p.id, id);
    p.pension = pension;

    // Add person to database
    new_db[i] = p;

    // Set new NULL member at the end
    new_db[i+1].name = NULL;

    printf("%s added succesfully.\n", name);
    return new_db;
}

void print_pensioners(struct Person *db) {
    // Get the size of the data set
    int sz = 1;
    while (db[sz-1].name != NULL) sz++;

    // Go through each person
    unsigned int i = 0;
    while (db[i].name != NULL) {
        printf("Name: %s, Social security number: %s, Monthly pension: %0.2f €.\n", db[i].name, db[i].id, db[i].pension);
        i++;
    }

    return;

}

int main(void)
{
    // Implement main function
    struct Person *db = malloc(sizeof(struct Person));
    if (db == NULL) {
        printf("Memory allocation failed.\n");
        free(db);
        return 0;
    }

    // Initialize name to NULL (needed?)
    db->name = NULL;

    // Add 3 people
    db = add_person("Matti Koskinen", "12341234123", 1500.50, db);
    db = add_person("Anna Aaltonen", "09876587463", 2500.95, db);
    db = add_person("Sauli Niinisto", "13579086421", 9999.99, db);
    db = add_person("Maher-shalal-hash-baz", "25738596836", 1234.43, db);

    // Print the data base
    print_pensioners(db);

    // Release memory
    unsigned int i = 0;
    while (db[i].name != NULL) {
        free(db[i].name);
        i++;
    }
    free(db);

    return 0;
}