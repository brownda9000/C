#include <stdlib.h>
#include <stdio.h>

#define WARN_IF(EXP)  \
      do{ if(EXP) fprintf(stderr, "Warning: " #EXP "\n"); }while(0)


/*
__attribute__((constructor)) 
	void hello() {
		printf("Hello!\n");
	}
*/
__attribute__((constructor(0))) 
	void hello() {
		printf("1st constuctor\n");
	}

__attribute__((constructor(1))) 
	void hello2() {
		printf("2nd constructor\n");
	}



__attribute__((destructor))
	void goodbye() {
		printf("Goodbye!\n");
	}

int main(void) {
	int x = 4;

	printf("Entered the main function.\n");

    WARN_IF(x == 0);
	return 0;
}
