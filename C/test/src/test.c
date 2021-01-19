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

int wordcompare ( char*  a, char*  b) {
    // Return 1 if a is greater than b
    int status = 0 ;
    
    if ( strcmp( a, b ) > 0 ) status = 1;
    
    return status;       
}

int wordcompare2 ( char*  a, char*  b) {
    // Return 1 if a is greater than b
    int status = 0 ;
    
    if ( strcmp( a, b ) < 0 ) status = -1;
    
    return status;       
}






int partition(int *arr, int lo, int hi, cmp_func f) {
    int i;
    int pivot;  // pivot stores the right most item  value
    int j;      // loop var

    pivot = arr[hi];   
    
    i = lo;

    for (j=lo; j< hi; j++) {
        if (f(arr[j] , pivot) == 1 ) { // Sort Ascending of Descending
            swap(arr,i,j);
            i++;
        }
     
    
 
    }  
    swap(arr,i,hi);
    
    return i; // Return pivots position in the array
}

void quicksort( int *arr , int lo, int hi,  cmp_func f) {
    int p; // Index value of the pivotal value
    
    if ( lo < hi ) {
         p=partition(arr, lo, hi, f );
         quicksort(arr,lo, p - 1, f); // Left side of pivotal value to be sorted
         quicksort(arr,p+1, hi,f) ;  // Right side of pivotal value to be sorted

    }
}

int main( int argc, char **argv)
{
   int x,y;

   char stry[20] = "zebra";   
   char strx[20] = "airport";

if ( wordcompare(strx,stry) > 0 )
      printf(" str=%s  and str=%s [greater than zero]\n",strx,stry);

if ( wordcompare2(strx,stry)  < 0 )
   printf(" str=%s and str=%s [less than zero]\n",strx,stry);
   return 0;
}
