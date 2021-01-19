#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv) {

    if ( argc != 3 ) {
       printf("Usage : %s  libraryname int\n", argv[0]);
	   return EXIT_FAILURE;
	}

	char *libpath = argv[1];

    int num = atoi(argv[2]);

	void *libhandle = dlopen(libpath, RTLD_LAZY);

	if ( libhandle == NULL )
		perror("ERROR: dlopen");

	 // Declare the function pointer
     int  (*opfunc) (int,int);
     char* (*getnamefunc) ();

	 // Assign the addNum function pointer to opfunc pointer
     opfunc = dlsym(libhandle,"addNum");
     getnamefunc = dlsym(libhandle,"getLibName");

     if ( opfunc == NULL | getnamefunc == NULL ) {
		 perror("ERROR: Could not open dynamic library");
		 return EXIT_FAILURE;
     }

     printf("Library name is : %s\n", getnamefunc());
     printf("%d --> %d\n", num, opfunc(num,4)) ;
   
    // close the dynamic library
	dlclose(libhandle);
}
