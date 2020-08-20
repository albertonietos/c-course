#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char name[80];
    int hitpoints;
    char weaponname[80];
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

    //printf("Index where new fighter is inserted in DB: %d\n", i);
    
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

    /* while (i != -1) {
        printf("i=%d: %s %d %s %d\n", i, new_db[i].name, new_db[i].hitpoints, new_db[i].weapon.name, new_db[i].weapon.max_damage);
        i--;
    } */

    printf("Added successfully!\n");
    return new_db;
}

struct fighter *attack(char *cmd, struct fighter *db) {
    char attack_name[80];
    char tgt_name[80];

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

    printf("Attacker index is %d, target index is %d.\n", i, j);

    printf("%s attacked %s with %s by %d damage. ", db[i].name, db[j].name, db[i].weapon.name, db[i].weapon.max_damage);
    
    // Decrement target's HP by damage of attacker
    db[j].hitpoints -= db[i].weapon.max_damage;
    printf("%s has %d hitpoints remaining. ", db[j].name, db[j].hitpoints);

    // Increment experience points of attacker by the amount of damage inflicted on the target
    db[i].exp += db[i].weapon.max_damage;
    printf("%s gained %d experience points.\n", db[i].name, db[i].weapon.max_damage);
    return db;
}

void list_characters(struct fighter *db) {
    unsigned int i = 0;
    printf("%s %d %s %d\n", db[i].name, db[i].hitpoints, db[i].weapon.name, db[i].weapon.max_damage);

    /*while (db[i].name != NULL || i > 10) {
        printf("%s %d %s %d", db[i].name, db[i].hitpoints, db[i].weaponname, db[i].weapondamage);
    }*/
    return;
}


int main(void) {
    struct fighter *db = malloc(sizeof(struct fighter));    
    int repeat = 1;
    char buffer[80];

    while(repeat) {
        char *ret = fgets(buffer, 80, stdin);

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
}