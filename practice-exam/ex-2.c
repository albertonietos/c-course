#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *mystrchr(char *str, char c)
{
    do {
        if (*str == c) return str;
    } while (str++);
    return NULL;
}

int *createArray(unsigned int size)
{
    int *array = malloc(sizeof(int) * size);
    for (unsigned int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}

struct products {
    char *title;
    double price;
};

struct products *add_product(struct products *array, unsigned int length,
                             const char *newtitle, double newprice)
{
    struct products *np = realloc(array,
                                 (length+1) * sizeof(struct products));
    np->title = malloc(sizeof(char) * (strlen(newtitle) + 1));                        
    strcpy(np->title, newtitle);
    np->price = newprice;
    return np;
}

// implement the main function for this
int main(void) {
    // Ex 2.a
    char str[10] = "bla r bla";
    char c = 'r';
    char *res = mystrchr(str, c);
    printf("%s\n", res);

    // Ex 2.b
    unsigned int n = 5;
    int *numbers = createArray(n);
    for (int i = 0; i < n; i++) {
        printf("%d", numbers[i]);
    }
    printf("\n");

    // Ex 2.c
    const char *newtitle = "End of the world!";
    double newprice = 20.0;
    unsigned int length = 1;

    char name[] = "Sharknado";
    //struct products product_1 = {name, 25.0};
    struct products array = {name, 25.0};
    array = add_product(&array, length, newtitle, newprice);
}
