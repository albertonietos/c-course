#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projekti.h"

#define MAX_LENGTH 80

struct fighter *add_character(char *name, int hitpoints, int exp, char *weaponname, int weapondamage, struct fighter *db) {
    // Increase i until we arrive at array member with NULL name
    unsigned int i;
    for (i = 0; db[i].name != NULL; i++);

    // Make sure that the character does not already exist in the database
    unsigned int j = 0;
    while (db[j].name != NULL) {
        if (strcmp(db[j].name, name) == 0) {
            printf("This character is already in the database.\n");
            return db;
        } else {
            j++;
        }
    }

    // Increase size of the database by one, and reserve space for final NULL member
    struct fighter *new_db = realloc(db, sizeof(struct fighter) * (i + 2));
    if (new_db == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Add character to database
    struct fighter f;
    f.name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(f.name, name);
    f.hitpoints = hitpoints;
    f.exp = exp;
    f.weapon.name = malloc(sizeof(char) * (strlen(weaponname) + 1));
    strcpy(f.weapon.name, weaponname);
    f.weapon.max_damage = weapondamage;
    new_db[i] = f;

    // Set new NULL member at the end
    new_db[i+1].name = NULL; 
    new_db[i+1].exp = 0;

    printf("Added successfully!\n");
    return new_db;
}

struct fighter *attack(char *cmd, struct fighter *db) {
    char attack_name[MAX_LENGTH];
    char tgt_name[MAX_LENGTH];

    if (sscanf(cmd, "H %s %s", attack_name, tgt_name) < 2) {
        printf("Invalid attack command: %s", cmd);
    }

    // Find attacker's index in database
    unsigned int i = 0;
    while (db[i].name != NULL) {
        if (strcmp(db[i].name, attack_name) == 0) {
            break;
        } else {
            i++;
        }
    }

    // Find target's index in database
    unsigned int j = 0;
    while (db[j].name != NULL) {
        if (strcmp(db[j].name, tgt_name) == 0) {
            break;
        } else {
            j++;
        }
    }

    // Catch situations where one of the fighters is not in the database
    if (db[i].name == NULL || db[j].name == NULL) {
        printf("One of the characters is not in the database. Try again.\n");
        return db;
    }

    // Catch situations where dead people try to attack
    if (db[i].hitpoints == 0) {
        printf("%s can not attack %s because he/she is dead.\n", db[i].name, db[j].name);
        return db;
    } else if (db[j].hitpoints == 0) {
        printf("%s was attacked by %s, but he was already dead. No experience gained.\n", db[j].name, db[i].name);
        return db;
    }

    printf("%s attacked %s with %s by %d damage. ", db[i].name, db[j].name, db[i].weapon.name, db[i].weapon.max_damage);
    
    // Decrement target's HP by damage of attacker
    db[j].hitpoints -= db[i].weapon.max_damage;

    // Minimum amount of HP is zero
    if (db[j].hitpoints < 0) db[j].hitpoints = 0;
    printf("%s has %d hitpoints remaining. ", db[j].name, db[j].hitpoints);

    // Increment experience points of attacker by the amount of damage inflicted on the target
    db[i].exp += db[i].weapon.max_damage;
    printf("%s gained %d experience points.\n", db[i].name, db[i].weapon.max_damage);
    
    return db;
}

void list_characters(struct fighter *db) {
    // Check if database is empty
    if (db[0].name == NULL) {
        printf("Database contains no characters.\n");
        return;
    }

    // Get number of elements in database
    /* unsigned int sz = 1, n = 0;
    while (db[n].name != NULL) {
        n++;
        sz++;
    } */
    int sz = 1;
    while (db[sz-1].name != NULL) sz++;

    // Sort the list indices based on the experience points
    struct fighter buffer;
    for (unsigned int i = 0; i < sz; i++) {
        for (unsigned int j = i + 1; j < sz; j++) {
            // If exp points of i is smaller than the next swap them
            if (db[i].exp < db[j].exp) {
                buffer = db[i];
                db[i] = db[j];
                db[j] = buffer;
            }
        }
    }

    // Print ordered database
    unsigned int i = 0;
    while (db[i].name != NULL && db[i].hitpoints > 0) {
        printf("%s %d %d %s %d\n", db[i].name, db[i].hitpoints, db[i].exp, db[i].weapon.name, db[i].weapon.max_damage);
        i++;
    }

    // Print the dead characters at the end
    while (db[i].name != NULL && db[i].hitpoints == 0) {
        printf("%s %d %d %s %d\n", db[i].name, db[i].hitpoints, db[i].exp, db[i].weapon.name, db[i].weapon.max_damage);
        i++;
    }
    return;
}

int save_game(struct fighter *db, char *filename) {
    // Open file for writing
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Opening of file failed. Game not saved.\n");
        return 0;
    }

    // Write one character at a time to file
    unsigned int i = 0;
    while (db[i].name != NULL) {
        fprintf(file, "%s %d %d %s %d\n", db[i].name, db[i].hitpoints, db[i].exp, db[i].weapon.name, db[i].weapon.max_damage);
        i++;
    }

    // Close file
    fclose(file);

    return 1;
}

struct fighter *load_game(char *filename) {
    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Opening of file failed. Game not loaded.\n");
        return NULL;
    }

    // Replace current database with a new one
    struct fighter *new_db = malloc(sizeof(struct fighter));
    if (new_db == NULL) {
        printf("Memory allocation failed.\n");
        free(new_db);
        return NULL;
    }

    char name[MAX_LENGTH];
    int hitpoints;
    int exp;
    char weaponname[MAX_LENGTH];
    int weapondamage;
    while (fscanf(file, "%s %d %d %s %d", name, &hitpoints, &exp, weaponname, &weapondamage) == 5) {
        new_db = add_character(name, hitpoints, exp, weaponname, weapondamage, new_db);
    }

    // Close file
    fclose(file);

    return new_db;

}

void release_fighter(struct fighter f) {
    free(f.name);
    free(f.weapon.name);
    //free(f);
}

int main(void) {
    struct fighter *db = malloc(sizeof(struct fighter));
    if (db == NULL) {
        printf("Memory allocation failed.\n");
        free(db);

    }
    // Initialize value for name to NULL and experience to 0 points
    db->name = NULL;
    db->exp = 0;

    int repeat = 1;
    char buffer[MAX_LENGTH];

    while(repeat) {
        char *ret = fgets(buffer, MAX_LENGTH, stdin);

        if (ret == NULL) {
            printf("fgets returns NULL\n");
            break;
        }

        switch (ret[0])
        {
        case 'A': {  // brackets needed because of variable declarations
            char name[MAX_LENGTH], weaponname[MAX_LENGTH];
            int hitpoints, weapondamage;
            int exp = 0;  // characters start with 0 experience points
            if (sscanf(buffer, "A %s %d %s %d", name, &hitpoints, weaponname, &weapondamage) < 4) {
                printf("Invalid add command: %s\n", buffer);
                break;
            }

            db = add_character(name, hitpoints, exp, weaponname, weapondamage, db);
            break;
        }

        case 'H':
            db = attack(buffer, db);
            break;

        case 'L':
            list_characters(db);
            break;

        case 'W': {
            // Check input
            char filename[MAX_LENGTH];
            if (sscanf(buffer, "W %s", filename) < 1) {
                printf("Invalid saving command: %s", buffer);
                break;
            }

            // Save all characters in the game to 'filename'
            if (save_game(db, filename)) {
                printf("Game saved succesfully!\n");
            }
            break;
        }

        case 'O': {
            char filename[MAX_LENGTH];
            if (sscanf(buffer, "O %s", filename) < 1) {
                printf("Invalid loading command: %s", buffer);
                break;
            }

            // Load characters into the game from 'filename'
            db = load_game(filename);
            if (db != NULL) {
                printf("Game loaded successfully!\n");
            }
            break;
        }

        case 'Q':
            // To exit program, we change the value of repeat to 0 to exit loop
            printf("Bye!\n");
            repeat = 0;
            break;

        default:
            printf("Invalid command.\n");
            break;
        }
    }

    // release memory and cleanup
    unsigned int i = 0;
    while (db[i].name != NULL) {
        release_fighter(db[i]);
        i++;
    }
    free(db);

    return repeat;
}