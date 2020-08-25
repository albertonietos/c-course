#include <stdlib.h>
#include <stdio.h>

char *mystrcat(char *dest, const char *src) {

    int i = 0;
    while (dest[i] != '\0') ++i;
 
    unsigned int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        ++i;
        ++j;
    }

    dest[i] = '\0'; 
    
    return dest;
}

unsigned int pickmax(unsigned int *numbers) {
    unsigned int max_id = 0;
    unsigned int i = 1;

    while (numbers[i] != 0) {
        if (numbers[i] > numbers[max_id]) {
            max_id = i;
        }
        i++;
    }

    return numbers[max_id];
}

void set_bit(unsigned char *buffer, unsigned int n, int bit) {
    for (int i = 0; i < n; i++) {
        
    }
}


int main(void) {

    // Exercise 1.a
    char dest[80] = "Alberto ";
    const char src[] = "Nieto";
    char *res = mystrcat(dest, src);

    printf("result: %s\n", res);

    // Exercise 1.b
    unsigned int numbers[5] = {1, 3, 4, 64, 0};
    printf("Maximum number is %d\n", pickmax(numbers));


    return 0;
}