#ifndef PROJECT
#define PROJECT


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

/* Adds a character with given name. The character has initially HP hit points, 
and the given weapon, with maximum damage as indicated in "weapondamage". */
struct fighter *add_character(char *name, int hitpoints, int exp, char *weaponname, int weapondamage, struct fighter *db);

/* Character “attacker” will attack towards character “target”. 
As the result target’s hit points will be decremented by the damage caused 
by the weapon (that can be randomized, if you wish). 
The outcome of attack must be printed to the user. */
struct fighter *attack(char *cmd, struct fighter *db);

/* Prints all characters added to the game, each on their own line. 
For each character all the above described properties must be printed (name, HP, Exp, Weapon). 
The characters should be ordered by their experience points: 
the chactacter with most experience points will be printed first. 
However, the dead characters should be printed at the end of the list, 
regardless of their experience points. */
void list_characters(struct fighter *db);

/* The commands start with one captial letter and may be followed by some number of parameters, 
separated by space, depending on the command. */
int save_game(struct fighter *db, char *filename);

/* Loads characters from file name “filename”, replacing the current setup in memory. */
struct fighter *load_game(char *filename);

/* Method to release memory allocated to each fighter */
void release_fighter(struct fighter f);

#endif