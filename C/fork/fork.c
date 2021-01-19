#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h> 
#include <unistd.h>


int main() {

    if (fork() == 0 ) 
       printf("C is a wonderful programming language. %d(parent) \n", getpid());  
	else
       printf("C is a wonderful programming language. %d \n", getpid());  
}
