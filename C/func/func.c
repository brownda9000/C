
/*************************************************************
Author : David Brown
Description:
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <strings.h>

char a() {
	    return 'm';
}

int main()
{
   typedef char (*PFC)();
   PFC z;

   z = a;

   printf("I am %c\n", z());

   return 0;
}
