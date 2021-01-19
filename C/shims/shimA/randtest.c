#include <stdio.h>
#include <stdlib.h>

#define MAX 5 
int main() {

    for (int  i=0 ; i<MAX; i++) {
        printf("Random number is %d\n", rand());
    }
    return EXIT_SUCCESS;
}
