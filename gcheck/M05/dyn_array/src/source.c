
#include "source.h"
#include "stdlib.h"
#include "stdio.h"

/* Dynamic Array Reader */
/* Parameters:
 * n: Number of values to be read
 * 
 * Returns: pointer to the dynamically allocated array
 */
int *create_dyn_array(unsigned int n)
{
    int *array = malloc(n * sizeof(int));
    
    if (array) {
        for (unsigned int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
    }
    return array;
}

/* Add to array */
/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 * 
 * Returns: pointer to the allocated array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
    int *new_array = realloc(arr, (num + 1) * sizeof(int));
    if (new_array == NULL) {
        return NULL;
    }
    new_array[num] = newval;
    return new_array;
}