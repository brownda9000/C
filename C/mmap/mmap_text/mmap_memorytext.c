#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
//#include <xlocale.h>
#include <ctype.h>

//#define PAGESIZE 4096

int main( int argc, char** argv )
{
	// READ file 
	//int fd = open("./beatles.txt", O_RDONLY, S_IRUSR| S_IWUSR);
	// Read/Write file
	int fd = open("./beatles.txt", O_RDWR, S_IRUSR| S_IWUSR);
	struct stat sb;

	if (fstat(fd, &sb) == -1 ) {
       perror("could not get file size \n");
    }   

    printf("file size is %ld\n", sb.st_size);

	// Read file into memory as READ
	//char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	// Read file into memory as Read/Write
	char *file_in_memory = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

   printf("Print file as an array of characters\n"); 

   for (int i=0; i < sb.st_size; i++ ) { 
	   // change character to upper case
	   file_in_memory[i] = toupper(file_in_memory[i]);
	   // 
       printf("%c", file_in_memory[i]);
   }

   printf("\n");

   // Unallocate memory
   munmap(file_in_memory, sb.st_size);
   // close file 
   close(fd);
}
