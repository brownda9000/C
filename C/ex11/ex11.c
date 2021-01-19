
/*************************************************************
Author : David Brown
Description: Pointers to functions
Version :
Date: 26th July 2020
**************************************************************/
#include <stdio.h>
#include <strings.h>
#include <stdlib.h> // For malloc
#include "../local/include/localdebug2.h"
#define BIG_NUMBER (64 * 1024 * 1024)

int add (int a, int b) {
     return a + b;
}

void inc_every_n(int *array, int incr) {
   for (int i = 0; i < BIG_NUMBER; i += incr)
      array[i] = 0;
}



int main()
{
   // Malloc an array
   int *array = malloc(sizeof(int)*BIG_NUMBER);

   int (*plus) (int,int) = add;
   typedef int (*addition_func)(int,int);
   addition_func add_func = add;

   time_it((callback_t) add, 15,17 ,"addition example");
   time_it2(inc_every_n, array,1 ,"Initialize every element in the array\n");
   time_it2(inc_every_n, array,8 ,"Initialize every 8th element in the array\n");
   time_it2(inc_every_n, array,16 ,"Initialize every 16th element in the array\n");

   printf("Add function : %d\n", add(6,9));
   printf("Add function : %d\n", plus(16,9));
   printf("Add function : %d\n", add_func(16,19));


   return 0;
}
