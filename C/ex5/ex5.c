
/*************************************************************
Author : David Brown
Description: Practicing with strings
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <strings.h>

int main()
{
   char buff[25];

   printf("Please enter a string :");
   //scanf("%s", buff );
   scanf("%24[^\n]", buff );

   printf("string entered is %s\n", buff);

   return 0;
}
