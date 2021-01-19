#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared_memory.h"

int main(int argc, char * argv[]){
	 if ( argc != 1 ) {
		 printf("usage - %s" , argv[0]);
		 return EXIT_FAILURE;
     }

    // grab the shared memory block
	 char *block = attach_memory_block(FILENAME, BLOCK_SIZE);
     if ( block == NULL ) {
		perror("ERROR: Could not get block");
		return -1;
	 }

	 printf("Reading: \"%s\"\n", block);

	 detach_memory_block(block);

	 return EXIT_SUCCESS;

}
