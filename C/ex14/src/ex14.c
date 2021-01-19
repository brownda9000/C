
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
#include<ctype.h>


typedef int (*cmp_func)(char *, char*); 

#define BUFFSIZE 1024
#define ARRAYSIZE 26  // Letters in the alphabet 

struct words {
     char word[50] ;  
     int  freq;      // Number of occurences of the word
     struct words *next;
};


struct words* findword(struct words *head, char *word) {
    struct words *wordsptr = head;
    struct words *tmp = NULL;

    // Try locate word inthe word list
    while ( wordsptr != NULL ) {
         if ( strlen(wordsptr->word) == strlen(word) ) {
            if ( strcmp(wordsptr->word, word) == 0 ) { // Found word so return word ptr 
               tmp = wordsptr;
            }
         }
         wordsptr=wordsptr->next;
         
         if ( tmp != NULL )  wordsptr = NULL;  // We have found the word
    }

    return tmp;
}

int alphachar(char ch) {
   int  status = -1 ;
   if ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ) {
      status = 0;
   }

   return status;
}
char* stripwhitespace(char* str) {
     int i,j=0;
     int count = 0;
     int len = strlen(str);
       
     for (i=0; i < strlen(str) ; i++ ) {
        
         if ( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ) {             
            str[j] = str[i];
            j++;
         }
         else {
             count++;
         }

         

      }

      if ( count >= 1 ) {
            str[(len - count)] = '\0';
      }

    return str;
}

void wordstats(struct words *word_arr[ARRAYSIZE] , int totalwords) {
   struct words *wordlist ; 
   float percentage;
   int accfreq=0;
   
   int i ;

   for (i=0; i < ARRAYSIZE ; i++ ) {  // For each letter of the alphabet print word list word_arr[0] = word beginning with a
      wordlist = word_arr[i];
      while ( wordlist != NULL ) {
         accfreq += wordlist->freq;
         percentage=((float)wordlist->freq/totalwords)*100;
         printf(" %25s\t%d\t %3f %%\n", wordlist->word, wordlist->freq, percentage );
         wordlist = wordlist->next;
      }
   }
   printf("Total acc freq %d Total words is %d\n", accfreq,totalwords);
}

char* strlwr ( char *strin) {
      int i;
       for (i=0; i < strlen(strin) ; i++ ) {
            strin[i] = tolower(strin[i]);
       }
    return strin;
}

int  parseline ( char *line , struct words *word_arr[ARRAYSIZE], int totalwords ) {
   const char delimeter[2]=" ";
   char *field;
   struct words *word, *wordptr, *head;
   int index;

   field = strtok(line, delimeter );	  

	  
	  while ( (field != NULL) && (alphachar(field[0]) == 0 ) ) {
		    //
          field = stripwhitespace(field);
          field = strlwr(field);
         
          //printf("Word to add is %s and status is %d\n", field, alphachar(field[0]) );
          index = field[0] - 'a';
          head =   word_arr[index]; // Use first letter to retrieve the alphabetic head pointer of the word list 

          wordptr = findword(head, field);

          totalwords++;

          // Add new word to word list
          if (  wordptr == NULL ) {  

             
              word = (struct words*) malloc(sizeof(struct words)) ;

              if ( word == NULL )
                  printf("Error allocating memory"); 
              
              if ( head != NULL) {    // We have new word to add to word list 
                  strcpy(word->word, field) ;
                  word->next = head->next;
                  head->next = word;
                  word->freq = 1;
                      // New word becomes the head of the word list
              }
          }
          else {
              
              wordptr->freq++; // Increase the occurence of word counter by one
          }

		    field = strtok(NULL, delimeter );  // get next field 
     }
			
    //wordstats(word_arr);
    
   return totalwords;
}
//
//  quicksort 
//

/*

int compare2 ( int a, int b) {
    // Return 1 if a is less than b
    int status = -1;
    
    if ( a < b ) status = 1;
    
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

void quicksort( words *arr , words *lo, words *hi,  cmp_func f) {
    int p; // Index value of the pivotal value
    
    if ( lo < hi ) {
         p=partition(arr, lo, hi, f );
         quicksort(arr,lo, p - 1, f); // Left side of pivotal value to be sorted
         quicksort(arr,p+1, hi,f) ;  // Right side of pivotal value to be sorted

    }
}
*/

int main( int argc, char **argv)
{
   
   char buf[BUFFSIZE] ;
   FILE *fp    = fopen("warandpeace.txt", "r");
   struct words *word_arr[ARRAYSIZE];
   //struct words *head;
   int i=1, totalwords=0 ;


   for (i=0; i < ARRAYSIZE; i++ ) {
      word_arr [i] = (struct words*) malloc(sizeof(struct words)) ;
   }

   

   if ( fp == NULL ) {
      fprintf(stderr,"File cannot be opened.\n");
      exit(1);
   }
   
   while (fgets(buf, 1024, fp)) {
		buf[strlen(buf)-1]='\0';  // remove carriage return from line buffer
      totalwords = parseline(buf, word_arr, totalwords);
      
      
      i++;
     
      
   }

   wordstats(word_arr,totalwords);
   //printf("Max words is %d", totalwords);
   return 0;
}
