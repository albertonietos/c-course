#include <stdio.h>

int main(void) {
    int repeat = 1;
    char buffer[80];

    while(repeat) {
        char *ret = fgets(buffer, 80, stdin);

        if (ret == NULL) {
            printf("fgets returns NULL\n");
            break;
        }

        switch (ret[0])
        {
        case 'A':
            /* code */
            break;
        
        default:
            break;
        }
    }
}