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
#include <pthread.h>

#define COUNT_TO 10
#define MAX_CORES 4

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long i = 0;

void *start_counting( void *arg) {
   int num;

   num =  (int) arg;

   printf("Start Function start_counting: num = %d\n", num);

   for (;;) {

      // acquire lock
       pthread_mutex_lock(&mutex);

      if ( i >= COUNT_TO ) {
         pthread_mutex_lock(&mutex);
          printf("End Function start_counting\n");
         return NULL;
    
      }
      i++;

      // release lock
       pthread_mutex_unlock(&mutex);

      printf("Num=%d  i = %lld\n", num,i);
   }
}

int main( int argc, char **argv)
{
   int i =0;

   pthread_t *thread_group = malloc(sizeof(pthread_t) * MAX_CORES);

   for (i = 0; i < MAX_CORES ; ++i) {
      pthread_create(&thread_group[i], NULL, start_counting, i);
   }

   for (i = 0; i < MAX_CORES ; ++i ) {
      pthread_join(thread_group[i], NULL);
   }

   return EXIT_SUCCESS;
}
