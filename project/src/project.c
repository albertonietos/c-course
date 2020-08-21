#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 80

struct weapon {
    char *name;  // name of weapon
    int max_damage;  // maximum damage of weapon
};

struct fighter {
    char *name;  // name of character
    int hitpoints;  // health of character (hitpoints)
    int exp;  // experience points that increase when character hits opponent (starts at 0)
    struct weapon weapon;
};

struct fighter *add_character(char *cmd, struct fighter *db) {
    char name[MAX_LENGTH];
    int hitpoints;
    char weaponname[MAX_LENGTH];
    int weapondamage;

    if (sscanf(cmd, "A %s %d %s %d", name, &hitpoints, weaponname, &weapondamage) < 4) {
        printf("Invalid add command: %s\n", cmd);
    }

    // Increase i until we arrive at array member with NULL name
    unsigned int i;
    for (i = 0; db[i].name != NULL; i++);

    // Increase size of the database by one, and reserve space for final NULL member
    struct fighter *new_db = realloc(db, sizeof(struct fighter) * (i + 2));
    if (new_db == NULL) {
        return NULL;
    }
    
    // Add character to database
    struct fighter f;
    f.name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(f.name, name);
    f.hitpoints = hitpoints;
    f.exp = 0;
    f.weapon.name = malloc(sizeof(char) * (strlen(weaponname) + 1));
    strcpy(f.weapon.name, weaponname);
    f.weapon.max_damage = weapondamage;
    new_db[i] = f;

    // Set new NULL member at the end
    new_db[i+1].name = NULL; 

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
    // Get number of elements in database
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
        fprintf(stderr, "Opening file failed. Game not saved.\n");
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


int main(void) {
    struct fighter *db = malloc(sizeof(struct fighter));    
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
        case 'A':
            db = add_character(buffer, db);
            break;
        
        case 'H':
            db = attack(buffer, db);
            break;

        case 'L':
            list_characters(db);
            break;

        case 'W': {  // brackets needed because of filename declaration
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
            if (load_game(db, filename)) {
                printf("Game loaded successfully!");
            }
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
    free(db);
}