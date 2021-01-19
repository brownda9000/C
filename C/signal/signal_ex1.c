#include<stdio.h> 
#include<signal.h> 
#include <unistd.h>


void handler1(int sig) 
{ 
	write(STDOUT_FILENO,"Signal trap - won't die",20);
} 

void handler2(int sig) 
{ 
	// see man 7 signal-safety
	write(STDOUT_FILENO,"trap segmentation fault - won't die",30);
} 

int main() 
{ 
    struct sigaction sa,sa2;
	sa.sa_handler = handler1;
	sa2.sa_handler = handler2;

	int *ptr = NULL;

    sigaction(SIGINT , &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
	
	signal(SIGSEGV, handler2); 

	while (1) {
		//*ptr = 45; // Cause segmentation fault
		sleep(1);
	}
		
    return 0; 
} 
