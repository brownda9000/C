#include <stdio.h>
#include <stdlib.h>

/*
void __cyg_profile_func_enter (void *this_func, void *call_site ) {
    printf("--> %p %p\n",this_func, call_site);
}

void __cyg_profile_func_enter (void *this_fn, void *call_site ) {
    printf("--> %p %p\n",this_fn, call_site);
}
*/

void f1() {
    printf("In f1\n");
}

void f2() {
    printf("In f2\n");
    f1();
}

int main () {

    f2();
    return EXIT_SUCCESS;
}