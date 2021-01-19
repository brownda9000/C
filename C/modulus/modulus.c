#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_SIZE 10
#define MAXNUM 100
#define PRINT_VAR(X) printf("Variable ("#X") value is %d at address %p\n", X, &X);
#define SWAP(A,B) A ^= B ^= A ^= B ;

void printIntArray(int array[] ) {

  for (int i=0; i < MAX_SIZE; i++ ) {
	  if (i==0) printf("[");
	  if (i==(MAX_SIZE - 1))     printf("%i]\n", array[i]);
	                      else   printf("%i,", array[i] ) ;
  }

}

int main() {
  int index = 0;
  int array [MAX_SIZE] = {0,1,2,3,4,5,6,7,8,9} ;
  int a=23,b=47;
  int ptr1 = 45;
  
  PRINT_VAR(ptr1)
  SWAP(a,b)
  PRINT_VAR(a)
  PRINT_VAR(b)
  
  for (int i=10 ; i < MAXNUM ; i++) {
	   index = i % MAX_SIZE;  // Determine array index using modulus
       array[index] = i;
       printIntArray(array);
       sleep(1); 
	  }

  return EXIT_SUCCESS;
}
