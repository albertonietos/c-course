
#include "source.h"


/* Selection sort */
/* Parameters:
 * start: start of an array
 * size: length of an array
 */
void sort(int *start, int size)
{
    for (int i = 0; i < size; i++) {
        // Assume the minimum to be in the starting position
        int min = start[i];
        int swap_id = i;
        // Inspect indices starting after i
        for (int j = i + 1; j < size; j++){
            if (min > start[j]) {
                min = start[j];
                swap_id = j;
            }
        }
    // Swap indices
    start[swap_id] = start[i];
    start[i] = min;
    }
}
