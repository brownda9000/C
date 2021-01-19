
/*************************************************************
Author : David Brown
Description:
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>


#define MAXFUNC 3

typedef int (*arith_func) (int,int) ;

int add( int a , int b) {
   return a + b;
}
int sub( int a , int b) {
   return a - b;
}
int mul( int a , int b) {
   return a * b;
}

typedef struct {
   char *function_name;
   arith_func f;
} function_map_type;

function_map_type function_map[MAXFUNC] = {
   {"add",add},
   {"sub",sub},
   {"mul",mul}
};

arith_func get_function( char *func_name ) {
   int i;

   // Look up function pointer using the function_map array
   //
   for (i=0;i < MAXFUNC; i++ ) {
      if ( strcmp(func_name,function_map[i].function_name) == 0 )
          return function_map[i].f;
   }
   return NULL; // return NULL if there is no match
}




int main( int argc, char **argv)
{
   int i,j;
   //arith_func op;

   if ( argc != 4 ) {
      printf("\n\tUSAGE: function_caller f arg1 arg2\n");
      exit(1);
   }
   
   arith_func f = get_function(argv[1]); // Lookup function pointer using a char string
   
   if ( f == NULL ) {
      printf("Cannot map function %s\n", argv[1]);
      exit(1);
   }
   
   i = atoi(argv[2]);  // Map char to integers
   j = atoi(argv[3]);

   /*
   op=add;
   printf("Add %d %d = %d\n", 4,18, op(4,18));
   op=sub;
   printf("Subtract %d %d = %d\n", 4,18, op(4,18)); 
   op=mul;
   printf("Multiple %d %d = %d\n", 4,18, op(4,18));  
   */

   printf("Multiple %d %d  f(i,j)= %d\n", i,j, f(i,j));     


   return 0;
}
