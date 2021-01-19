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

#define MAXNUM 1024

int main( int argc, char **argv)
{
    long int x,y,z;

   x = 0;
   y = 1;
   z = 0;

   while ( x < MAXNUM ) {
       printf("%ld ",x);
   
       x = y + z;
       z=y;
       y=x;



      
   }  

   return 0;
}
