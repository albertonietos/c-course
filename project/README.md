# Project: Fighters

Implement a small role playing game, in which the game characters fight against each other. For each character on should define at least

* **Name** that identifies the character.

* **Hit points** (HP) that defines the health of the character. HP is reduced when the character gets damage in the fight. The character will die when HP reduces to zero.

* **Experience points** (Exp) that increases when the character hits its opponents in the fight. You can decide how the experience points increase (for example, by the amount of inflicted damage, with bonus on slaying, etc,). The experience points always start from zero on a new character.

* **Weapon** (i.e., a string with the weapoin name), and its **maximum damage**. In the simpliest form the weapon can always inflict the same amount of damage, but you can define also so that a hit causes a random amount of damage.

In the game one can create arbitrary many characters, that are being tracked by the game.

The program has the following functions:

* A *name HP weaponname weapondamage* : **Add character** : Adds a character with given name. The character has *initially HP* hit points, and the given weapon, with maximum damage as indicated in “*weapondamage*”. For example: `A Bilbo 25 Dagger 8`. (1 p)

* *H attacker target* : **Attack** : Character “*attacker*” will attack towards character “target”. As the result target’s hit points will be decremented by the damage caused by the weapon (that can be randomized, if you wish). The outcome of attack must be printed to the user. For example: `H Bilbo Smeagol`. An example output could then be: “`Bilbo attacked Smeagol with Dagger by 6 damage. Smeagol has 8 hit points remaining. Bilbo gained 6 experience points`” (*1 p*)

* *L*: **List characters** : Prints all characters added to the game, each on their own line. For each character all the above described properties must be printed (name, HP, Exp, Weapon). The characters should be ordered by their experience points: the chactacter with most experience points will be printed first. However, the dead characters should be printed at the end of the list, regardless of their experience points. If output works, but the order is wrong, you will get one point. If the order is correct, you will get *max. 2 points*.

* *W filename* : Saves all characters in the game (including the dead ones) to file named “filename”. (*1 p*)

*O tiedosto* : Loads characters from file name “filename”, replacing the current setup in memory. (*1 p*)

* *Q* : **Exit program**: Quits program and releases all allocated memory. This function is must be implemented in order to detect possible memory leaks.

In addition to the above commands, there should be a working main function that repeatedly asks commands from user and acts accordingly.

The commands start with one captial letter and may be followed by some number of parameters, separated by space, depending on the command. Below is an example of possible input sequence:

```
A Bilbo 25 Dagger 8
A Gimli 45 Axe 12
A Smaug 120 Fire 18
H Bilbo Smaug
H Gimli Smaug
H Smaug Gimli
L
W game
Q
```

With these commands three characters are created. First Bilbo and Gimli will attack Smaug, that will attach back towards Gimli. After this the game situation is printed, and saved to file named “game”.

You can design your program in any way you want, but apply clear structure to logical functions, and name the functions and variables appropriately so that the program is easy to read. You can use at most one .h - header file (that must be named “projekti.h”) and one .c file. The header file is not mandatory, and you can do everything in single .c file if you want.

Other general requirements and instructions:

* To facilitate testing, the aforementioned command syntax must be precisely followed

* You must use dynamic memory to implement the storage. A large static array is not acceptable. The dynamic memory allocation should be done based on the actual need: malloc(1000000) is not acceptable.

* After every command, the system must give an output that tells whether the command was succesful, or whether its execution failed.

* You can assume a maximum lenght for user input line. For example, 80 characters is sufficient.

* Clearly erroneus commands must give on error message, and at least the program must not crash as result. However, you can assume that names and other strings not contain whitespaces (i.e., whitespaces can be assumed as command field separators).

# Evaluation criteria
* Each functionality that is implemented correctly: 1 point, in L-command max. 2 points (total max. 6 points)

* Working main function and command parsing: 2 points (required to pass)

* Appropriate programming style (distribution to functions, appropriate indentation, appropriate naming, comments as needed): 2 points

* Compiler gives warnings: max. -2 points

* There are valgrind errors: max. -2 points

Max: 10 points.

Each function must give a clear output that either confirms succesful operation, or an error message as needed.

The program will be compiled with the following gcc command line options: `-Wvla -Wall -g -std=c99`

If compilation gives errors that prevent creating an executable, or the given command line format is not exactly followed, the assignment cannot be accepted, and you will get no points. However, you can skip some of the non-mandatory functions, if you do not have enough time, or cannot do them. A good strategy is to proceed on functionality at a time and test it before starting to implement the next function.

The program will be evaluated and tested on this TIM server, that is based on Ubuntu 16.04 system. However, implement and test your program in a real development environment, because that way testing and coding will be easier (and we will spare the server capacity). Only submit the ready program in the end. Evaluation will happen manually, so you will not get any automatic feedback with the submission.

*Note*: The test input in TIM system will operate as a sort of file that ends in end-of-file mark. Be prepared to handle end of file in your program when you parse the user input. End of file may occur in any case also in normal use of the program.