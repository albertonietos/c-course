#include <ctype.h>
#include <stdio.h>

/*
 * Function, that calculates all characters in a string that are
 * non-alphabetical and returns the amount as an unsigned int.
 * Hint: ctype.h functions
 */
unsigned int count_non_alphabetical(const char* str) {
    unsigned int count = 0;
    while (*str != '\0') {
        if (!isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

void my_tests(void)
{
    // You can write your own test code here.
    const char *str = "f32ds/as";
    printf("%d", count_non_alphabetical(str));
}

int main(void)
{
    /* You may implement your own tests in my_tests function */
    my_tests();

    /* To enable automatic grading, uncomment the below
    function call for hidden function grading_tests */
    grading_tests();
}