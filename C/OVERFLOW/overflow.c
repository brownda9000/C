/*************************************************************
Author : David Brown
Description: Buffer overflow example: https://www.youtube.com/watch?v=V9lMxx3iFWU&feature=youtu.be
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char **argv)
{

   char password[16];
   printf("Enter your password: ");
   gets(password);

   if ( strcmp(password, "password1")) {
        printf("\nYou fail!");
   }
   else {
            granted();
   }
   return 0;
}

void granted() {
    printf("Granted !!!!");
}
