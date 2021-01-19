#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>  
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h> /* variadic function */
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <limits.h>
#include <pthread.h>
#include "myqueue.h"


#define SERVER_PORT 8989
#define BUFSIZE 4096 
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100
#define THREADPOOL_SIZE 20

pthread_t thread_pool[THREADPOOL_SIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// condition variable: lets threads wait until something happens and iyt can ..
// thread #1 wait
// thread #2 signal
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

typedef struct sockaddr_in SA_IN;
typedef struct sockaddr SA;

void* handle_connection(void*  pclient_socket);
int check(int exp , const char *msg);
void* thread_function(void *arg);


int main(int argc, char* argv[] ) {
    int server_socket, client_socket, addr_size;
	SA_IN server_addr, client_addr;

	//
	// Create/Initialise thread pool 
	//
	for (int i = 0; i < THREADPOOL_SIZE; i++) {
		pthread_create(&thread_pool[i], NULL, thread_function, NULL);
	}
    printf("IMPORTANT: this application is not secure it gives access to server files!!!!\n");
	// make a socket connection
    check(server_socket = socket(AF_INET, SOCK_STREAM,0),"ERROR:Socket Creation");

    server_addr.sin_family        = AF_INET;
	server_addr.sin_addr.s_addr   = INADDR_ANY;
	server_addr.sin_port = htons(SERVER_PORT);

	check(bind(server_socket, (SA*)&server_addr, sizeof(server_addr)),"ERROR socket binding") ;

	check(listen(server_socket, SERVER_BACKLOG), "ERROR socket listening");

	while ( true ) {
       printf("Waiting for connections...\n");

       addr_size = sizeof(SA_IN);

	   // wait for incoming connections
	   check(client_socket = accept(server_socket, (SA*) & client_addr, (socklen_t*) &addr_size),"ERROR accepting connection");

	   printf("Connection accepted\n");


	   
	   //pthread_t t;

	   // client_socket needs to be a point for pthread_create
	   int* pclient = malloc(sizeof(int));
	   *pclient = client_socket;

	   // Add a mutex lock to prevent a race condition
	   pthread_mutex_lock(&mutex);
       enqueue(pclient);
	   pthread_cond_signal(&condition_var);
       pthread_mutex_unlock(&mutex);
	   
	   /*
	   pthread_create(&t, NULL, handle_connection, pclient);
	   */

	   //handle_connection(client_socket);

    }


	return EXIT_SUCCESS;
}

void * thread_function(void *arg) {
   while (true) {
	   // Retrieve a thread from the pool
	   //
	   int *pclient;

       // Add a mutex lock to prevent a race condition
	   pthread_mutex_lock(&mutex);
	   if ( (pclient = dequeue() ) == NULL ) {
		   pthread_cond_wait(&condition_var, &mutex);
           // try again
		   pclient = dequeue();
	   }

	   
	   
	   pthread_mutex_unlock(&mutex);

	   if ( pclient != NULL) {
		   // we have a connection
	       handle_connection(pclient);
	   }

   }

}


// must be void pointer function for pthread
void * handle_connection(void*  pclient_socket) {
	int client_socket = *(int*)pclient_socket;  // Typecast the void pointer to an int pointer for compiler warning
	free(pclient_socket); // Not required only needed for pthread acceptance

    char buffer[BUFSIZE];
	size_t bytes_read = 0;
	int msgsize = 0;
	char actualpath[PATH_MAX+1];


	// Read the client message

	while ( (bytes_read = read(client_socket, buffer+msgsize, sizeof(buffer) - msgsize -1 )) > 0) {
         msgsize += bytes_read;
		 if (msgsize > BUFSIZE-1 || buffer[msgsize-1] == '\n') break;
    }

	buffer[msgsize-1] = 0; // null terminate buffer

	printf("REQUEST: %s\n", buffer);
	fflush(stdout);

	// 
	if ( realpath(buffer, actualpath) == NULL ) {

	    printf("ERROR(Bad path) : %s\n", buffer);
        close(client_socket);
		return NULL;
	}


	// read file contents and send it to the client

	FILE  *fp = fopen(actualpath, "r");
	if ( fp == NULL ) {
       printf("ERROR(open): %s\n", buffer);
	   close(client_socket);
	   return NULL;
    }	

	sleep(1);
	// Note: a real program would limit the client certain files
	while (( bytes_read = fread(buffer, 1, BUFSIZE, fp)) > 0 ) {
		printf("sending %zu bytes\n", bytes_read);
        write(client_socket, buffer, bytes_read);
    }
	close(client_socket);
	fclose(fp);
	printf("closing connection");

	return NULL;
}

int check( int exp, const char *msg) {
   if ( exp == SOCKETERROR) {
      printf("%s", msg);
	  return SOCKETERROR;
   }

   return EXIT_SUCCESS;

}
