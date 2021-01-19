// Compile with: gcc -o test -Wl,--wrap,malloc snippet.c
#include <stdlib.h>
#include <stdio.h>

extern void * __real_malloc(size_t);

void * __wrap_malloc(size_t c) {
	  printf("malloc called with %lu\n", c);
	    return __real_malloc(c);
}

int main(void) {
	  void *p = malloc(42);
	    if(p) free(p);
		  return 0;
}
