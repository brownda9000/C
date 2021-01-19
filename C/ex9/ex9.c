
/*************************************************************
Author : David Brown
Description:
Version : integer pointer example
Date:
**************************************************************/
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define MAXITEM 79            // Number ranges og integers
#define MIXITERATIONS 1000000 // Mix up block of integers X times
#define XRANDOM 6 // Pick X random numbers 

// TODO RANDOM number 4 times MAXITEM 
// TODO swap to two random places



int main()
{

   int *p;
   int i,tmp;
   int ptr1, ptr2;
   time_t t;

   /* Intializes random number generator */
   srand((unsigned) time(&t));

   //printf("Print random number %d\n", rand() % MAXITEM );

   // Allocate Memory for MAXITEM integers 
   p = malloc( MAXITEM * sizeof(int));
   if ( p == NULL)   printf("Couldn't allocate memory!");

   *p = 0; 
   
   // Populate the Block of  integers 
   for (i=0; i<MAXITEM; i++)
       *(p+i) = *p + i;	   


    // Mix up the block of integers
    for (i=0; i < MIXITERATIONS; i++ ) {

        ptr1 = rand() % MAXITEM;  // Select random num1
        ptr2 = rand() % MAXITEM;  // Select random num2

        // swap num1 and num 2
        tmp = *(p + ptr1);

        *(p + ptr1) = *(p + ptr2);
        *(p + ptr2) = tmp;
    }

   // Print the block of integers
   /*for (i=0; i<MAXITEM; i++)
        printf("Print integer %d\n", *(p+i) );
   */
   /* Intializes random number generator */
   srand((unsigned) time(&t));

    for (i=0; i < XRANDOM; i++ ) {
        ptr1 = rand() % MAXITEM; 

        printf(" %d ", *(p+ (*(p+ptr1))) );
    }
    printf("\n");

   
   free(p);
   return 0;
}
