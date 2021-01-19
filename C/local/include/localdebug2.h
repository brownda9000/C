#include <time.h>

#ifndef DEBUG
#define DEBUG 0
#endif
#define debug_printf(fmt, ...) \
do { if (DEBUG) { \
fprintf(stderr, "DEBUG %s[%d] %s() " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
fflush(stderr); } }while (0)

// Define pointer function type
typedef void (*callback_t) (int,int);

void time_it(callback_t f, int x, int y, char *msg) {
    clock_t start = clock();
	// Function call
    (*f)(x,y);

    clock_t end = clock();
    clock_t diff = end - start ;

    printf("%s:  %ld microseconds\n",msg , diff);

}

void time_it2(void (*f) (int *array, int incr), int *array , int incr , char *msg) {
    clock_t start = clock();
	// Function call
    (*f)( array , incr);

    clock_t end = clock();
    clock_t diff = end - start ;

    printf("%s:  %ld microseconds\n",msg , diff);

}
