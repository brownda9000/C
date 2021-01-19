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

#define MAXITER 10000000 

int main( int argc, char **argv)
{
   long int n;

   for (n=0;n< MAXITER; n++) {
      if ( (n*n) == (2 * n))
      printf("n=%ld    f=%ld\n", n, (n*n));

   }


   return 0;
}
