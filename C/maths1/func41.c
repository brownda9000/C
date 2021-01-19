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

#define MAXITER 45

int main( int argc, char **argv)
{
   int f,n;

   for (n=0;n< MAXITER; n++) {
      f = n*n -n + 41;
      printf("n=%d    f=%d\n", n, f);

   }


   return 0;
}
