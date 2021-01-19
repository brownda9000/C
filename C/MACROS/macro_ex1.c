#include <stdio.h>
#include <stddef.h>

#define COUNT_OF(ptr) (sizeof(ptr) / sizeof((ptr)[0]))

int main(void) {
    static const char *strings[] = {
        "Hello",
        "World",
        NULL
    };

    for (size_t i = 0 ; strings[i] != NULL; i++ )
        printf("Value is = %s\n", strings[i]);

    for (size_t i = 0 ; COUNT_OF(strings); i++ )
        printf("Value is = %s\n", strings[i]);
}