# Exam for ELEC-A7100 - Basic Course in C programming

## Ex 1 - String in C

Implement function `count_non_alphabetical`, that calculates all characters in a string that are non-alphabetical and returns the amount as an `unsigned int`.

Hint: `ctype.h` functions

## Ex 2 - Arrays in C

Implement function `median`, that calculates the median value of the integers in the array and returns it. The parameter `n` tells how many numbers there are in the array.

Note: median value is the middle value of an array when it has been ordered. There will always be an odd number of elements in the array. A function for comparing two elements in an array is with the exercise.

## Ex 3 - Bit operations

Implement function `count_set_bits_in_array`, that calculates the set bits in the array containing binary numbers. Parameter `n` tells how many binary numbers there are in the array.

So, for example, given `array = { 0xA3, 0x58 }`, the function would return 7, as `0xA3 = 10100011` in binary, and `0x58 = 01011000` in binary.

## Ex 4 - Fix program

The code below doesn’t work as it’s supposed to. Fix the functions so, that they work as the comments describe and don’t produce compiler errors or warnings, nor valgrind errors or memory leaks. The main function has no problems, and it cannot be changed. You can see the main function by pressing the “Näytä koko koodi” link (“Show the full code”) next to the run button. The structures are also defined correctly, and no includes are missing. In general, the logic of the code is correct.

The program handles map data, more specifically map tiles. The program saves them in a `Map` structure, that holds a location name, a `MapTile` linked list and the amount of tiles in the array. The `MapTile` structure holds the data for a single map tile, and stores the id of the map tile, the center coordinate (a latitude-longitude pair) of the tile and the size and the zoom level for the tile.

There are six mistakes in the program, each of them clearly visible either in the compiler errors/warnings or valgrind output. Note that there might be more than one error/warning per mistake as a single mistake can create many problems at once.

* There are two mistakes in the `createMapTile` function.
* There is one mistake in the `createMapTiles` function.
* There is one mistakes in the `createMap` function.
* There is one mistake in the `printTileInfo` function.
* There is one mistake in the `freeMemory` function.

## Ex 5 - Program: KELA (8 p)

Implement a KELA-registry that maintains the names and social security numbers of people, along with information of their monthly pension. For each person the following information should be stored:

* name (contains full name, and can be long)
* social security number (11 characters)
* monthly pension (in euros, but not necessary exact euro amounts, and can contains cents, too)
You cannot make assumptions about the maximum length of the name (some people have very long names).

Implement the following functions:

* **add_person**, that adds a new person to the registry.

* **print_pensioners**, that outputs all persons in the registry, along with their full information.

In addition, implement a main function that calls the above two functions. In main function, add at least three persons to the registry, and output its content afterwards.

The proram allocates its memory dynamically, but should only use as much memory as it really needs.

Scoring:

* appropriate data structures: 2p
* working add_person: 2p
* working print_pensioners: 2p
* working main function: 2p