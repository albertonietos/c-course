#include "gameoflife.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Exercise a: Allocates needed memory for the GameArea structure and
 * the actual game area. 'x_size' and 'y_size' indicate the horizontal and
 * vertical dimensions of the GameArea.
 * 
 * Returns: pointer to the GameArea structure allocated by this function.
 */
GameArea *createGameArea(unsigned int x_size, unsigned int y_size)
{
    // Allocate memory for cell values
    CellStatus **cells = malloc(y_size * sizeof(CellStatus *));
    if (cells == NULL) {
        free(cells);
        return NULL;
    }

    // Allocate memory for game area
    GameArea *area = malloc(sizeof(GameArea));
    if (area == NULL) {
        free(area);
        return NULL;
    }

    // Assign values to structure
    area->cells = cells;
    area->x_size = x_size;
    area->y_size = y_size;

    // Go thru game area and assign DEAD values to all cells
    for (unsigned int y = 0; y < y_size; y++) {
        // Allocate memory for rows of cells
        cells[y] = malloc(x_size * sizeof(CellStatus));
        if (cells[y] == NULL) {
            for (unsigned int j = 0; j < y; j++) {
                free(cells[j]);
            }
            free(cells);
            free(area);
            return NULL;
        }
        for (unsigned int x = 0; x < x_size; x++) {
            // Assign DEAD to cell in [y,x]
            cells[y][x] = DEAD;
        }
    }
    return area;
}

/* Free memory allocated for GameArea <a>.
 */
void releaseGameArea(GameArea *a)
{
    for (unsigned int y = 0; y < a->y_size; y++) {
        free(a->cells[y]);
    }
    free(a->cells);
    free(a);
}

/* Exercise b: Initialize game GameArea by setting exactly <n> cells into
 * ALIVE CellStatus in the game GameArea <a>.
 */
void initGameArea(GameArea *a, unsigned int n)
{
    // Count how many cells are alive
    unsigned int count = 0;

    while (count < n) {
        // Go thru every cell
        for (unsigned int y = 0; y < a->y_size; y++) {
            for (unsigned int x = 0; x < a->x_size; x++) {
                int prob = rand() % 100; // random number between 0 and 100
                if (prob > 80 && a->cells[y][x] == DEAD && count < n) {
                    a->cells[y][x] = ALIVE;
                    count++;
                }
            }
        }
    }
}

/* Exercise c: Output the current CellStatus of GameArea <a>.
 */
void printGameArea(const GameArea *a)
{
    for (unsigned int y = 0; y < a->y_size; y++) {
        for (unsigned int x = 0; x < a->x_size; x++) {
            if (a->cells[y][x] == DEAD) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

/* Calculates number of live neighbours around position (x,y),
 * and returns the count.
 */
unsigned int live_neighbours(const GameArea *a, unsigned int x, unsigned int y)
{
    unsigned int count = 0;
    for (int j = -1; j <= 1; j++) {
        for (int i = -1; i <= 1; i++) {
            if (((int)y + j) >= 0 && (y + j) < a->y_size) {
                if (((int)x + i) >= 0 && (x + i) < a->x_size) {
                    if (i != 0 || j != 0) {
                        if (a->cells[y+j][x+i] == ALIVE) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

/* Exercise d: Advance GameArea <a> by one generation.
 */
void gameTick(GameArea *a)
{
    // Create a copy of the GameArea
    GameArea *old_a = createGameArea(a->x_size, a->y_size); //initialize area
    if (old_a == NULL) {
        return;
    }
    // Fill area with values from previous iteration
    for (unsigned int y = 0; y < a->y_size; y++) {
        for (unsigned int x = 0; x < a->x_size; x++) {
            old_a->cells[y][x] = a->cells[y][x];
        }
    }

    // Go thru previous iteration's area and update current iteration
    for (unsigned int y = 0; y < a->y_size; y++) {
        for (unsigned int x = 0; x < a->x_size; x++) {
            unsigned int count = live_neighbours(old_a, x, y);
            if (count < 2 && old_a->cells[y][x] == ALIVE) {
                a->cells[y][x] = DEAD;
            } else if ((count == 2 || count == 3) && old_a->cells[y][x] == ALIVE) {
                a->cells[y][x] = ALIVE;
            } else if (count > 3 && old_a->cells[y][x] == ALIVE) {
                a->cells[y][x] = DEAD;
            } else if (count == 3 && old_a->cells[y][x] == DEAD) {
                a->cells[y][x] = ALIVE;
            }
        }
    }
    releaseGameArea(old_a);
}
