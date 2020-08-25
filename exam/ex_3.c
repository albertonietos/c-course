#include <stdio.h>

/*
 * Function, that calculates the set bits in the array containing binary
 * numbers. Parameter n tells how many binary numbers there are in the array.
 * So, for example, given array = { 0xA3, 0x58 }, the function would return 7,
 * as 0xA3 = 10100011 in binary, and 0x58 = 01011000 in binary.
 */
unsigned int count_set_bits_in_array(unsigned char* array, unsigned int n) {
    unsigned int count = 0;

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if (array[i] >> (7 - j) & 1) {
                count++;
            }
        }
    }
    return count;
}

void my_tests(void)
{
    // You can write your own test code here.
    unsigned int n = 2;
    unsigned char array[2] = { 0xA3, 0x58 };
    unsigned int count = count_set_bits_in_array(array, n);
    printf("%d", count);
}

int main(void)
{
    /* You may implement your own tests in my_tests function */
    my_tests();

    /* To enable automatic grading, uncomment the below
       function call for hidden function grading_tests */
    grading_tests();
}
