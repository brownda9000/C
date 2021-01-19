
/*************************************************************
Author : David Brown
Description: Bubble sort + QuickSort basic example
Version :
Date:
**************************************************************/
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <unistd.h> 


typedef int (*cmp_func)(int,int); 
#define  MAXARRAY 15

//
//   BEGIN BUBBLESORT
//
int compare ( int a, int b) {
    // Return 1 if a is greater than b
    int status = -1;
    
    if ( a > b ) status = 1;
    
    return status;       
}

int compare2 ( int a, int b) {
    // Return 1 if a is less than b
    int status = -1;
    
    if ( a < b ) status = 1;
    
    return status;
}

void bubblesort( int *arr , int n, cmp_func f ) {
    // TODO : compare function point  to allow ascending descending sort 
    int i, j, tmp;

    for (i=0 ; i < (n - 1) ; i++ ) {
        for (j=0; j < (n-1 ); j++ ) { 
              if ( f(arr[j],arr[j+1]) == 1) {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
	}
}

void print_array(int *arr, int size) {
    // Print integer array
    int i ;

    for (i=0 ; i < size ; i++ ) 
       printf("%d,", arr[i] );
    printf("\n");
}
//
//   END BUBBLESORT
//
//
//   BEGIN QUICKSORT
//
void swap(int *arr, int a, int b ) {
    // Swap two items in an integer array
    int temp;

     temp = arr[a];
     arr[a] = arr[b];
     arr[b] = temp;
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

//
//   END QUICKSORT
//

int main( int argc, char **argv)
{
   int i;
   char sorttype[20],sortorder[20];
   int arr [MAXARRAY] ;
   time_t t;
   
   int opt;

   while((opt = getopt(argc, argv, ":bqad:")) != -1)  
    {  
        switch(opt)  
        {  
            case 'b': strcpy(sorttype,"bubblesort");
                      break;  
            case 'q': strcpy(sorttype,"quicksort");
                      break;
            case 'a': strcpy(sortorder,"ascending");
                      break;  
            case 'd': strcpy(sortorder,"descending");
                      break;      
           
        }  
    } 

   // Populate integer array with random data
   srand((unsigned) time(&t));
   for (i=0 ; i < MAXARRAY ; i++ ) 
      arr[i] = rand() % 32000; 

   printf("%s Before\n", sorttype);
   print_array( arr, MAXARRAY );
    printf("P1 %s %s\n", sorttype,sortorder);
    if ( strcmp(sorttype,"quicksort")  == 0 && strcmp(sortorder,"descending") == 0 ) {
        printf("here");
          quicksort(arr, 0, MAXARRAY-1,compare ); 
    }
/*
   if ( strcmp(sorttype,"quicksort")  == 0 && strcmp(sortorder,"ascending") == 0 )   quicksort(arr, 0, MAXARRAY-1,compare2 ); // Sort in ascending order
   if ( strcmp(sorttype,"quicksort")  == 0 && strcmp(sortorder,"descending") == 0 )   quicksort(arr, 0, MAXARRAY-1,compare );  // Sort in descending order
   if ( strcmp(sorttype,"bubblesort") == 0 && strcmp(sortorder,"ascending") == 0 )   bubblesort( arr, MAXARRAY, compare );   // Sort in ascending
   if ( strcmp(sorttype,"bubblesort") == 0 && strcmp(sortorder,"descending") ==0 )  bubblesort( arr, MAXARRAY, compare2 );    // Sort in descending
*/
   printf("%s After\n", sorttype);
   print_array( arr, MAXARRAY);

/*
  printf("\nAscending sort\n");
  bubblesort( arr, MAXARRAY, compare );
  for (i=0 ; i < MAXARRAY ; i++ ) 
     printf("%d,", arr[i] );

  printf("\nDescending sort\n");
  bubblesort( arr, MAXARRAY, compare2 );
  for (i=0 ; i < MAXARRAY ; i++ ) 
     printf("%d,", arr[i] );
  printf("\n");
*/
  
 
   return 0;
}
