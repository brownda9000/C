#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

#define NUM_THREADS 26

void *print_hello(void *threadid) {
 long tid; 
 int i;

 tid = (long) threadid; 
 printf("Hello World! It’s me, thread #%ld!\n", tid);

 for (i=0; i < 12; i++ ) {
   printf(" tid=%ld   x  i = %d  = %ld\n", tid,i, (tid*i));
 }
 
 pthread_exit(NULL); 
}

int main (int argc, char *argv[]) 
{ 
  pthread_t threads[NUM_THREADS]; 
  int rc; long t; 
  
  for (t = 0; t < NUM_THREADS; t++) { 
      printf("In main: creating thread %ld\n", t); 
      rc = pthread_create(threads + t, NULL, print_hello, (void *) t); 

     if (rc) { 
           printf("ERROR; return code from pthread_create() is %d\n", rc); 
           exit(-1); 
     } 
   } /* wait for all threads to complete */ 

   for (t = 0; t < NUM_THREADS; t++) {
       pthread_join(threads[t], NULL);
   } 

  pthread_exit(NULL); 

}

