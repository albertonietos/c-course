#include <stdio.h>
#include <stdlib.h>

struct fighter {
    char *name;  // name of character
    int hitpoints;  // health of character (hitpoints)
    int exp;  // experience points that increase when character hits opponent (starts at 0)
    char *weaponname;  // name of weapon
    int weapondamage;  // damage of weapon
};

struct fighter *add_character(char *cmd, struct fighter *db) {
    char name[80];
    int hitpoints;
    char weaponname[80];
    int weapondamage;
    if(sscanf(cmd, "A %s %d %s %d", name, &hitpoints, weaponname, &weapondamage) < 2) {
        printf("Invalid add command: %s\n", cmd);
    }

    // allocate memory 
    struct fighter *character = malloc(sizeof(struct fighter));

    // Assign values
    character->name = name;
    character->hitpoints = hitpoints;
    character->exp = 0;
    character->weaponname = weaponname;
    character->weapondamage = weapondamage;

    printf("Added successfully!\n");
    return db;
}

int main(void) {
    struct fighter *db = NULL;    
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