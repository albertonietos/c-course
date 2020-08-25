#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

/*
 * Function, that calculates the median value of the integers in the array
 * and returns it. The parameter n tells how many numbers there are in the
 * array.
 * Note: median value is the middle value of an array when it has been ordered.
 * There will always be an odd number of elements in the array.
 * A function for comparing two elements in an array is provided above.
 */
int median(int* array, unsigned int n) {
    qsort(array, n, sizeof(int), compare);

    return array[n/2];
}

void my_tests(void)
{
    // You can write your own test code here.
    int values[] = {3, 50, 1, 35, 36};
    unsigned int n = 5;
    printf("%d", median(values, n));
}

int main(void)
{
    /* You may implement your own tests in my_tests function */
    my_tests();

    /* To enable automatic grading, uncomment the below
    function call for hidden function grading_tests */
    //grading_tests();
}