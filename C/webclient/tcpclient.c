#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define SERVER_PORT 80

#define MAXLINE 4096

#define SA struct sockaddr

void err_n_die(const char *fmt, ...);

int main(int argc, char* argv[] ) {
   int                 sockfd, n;
   int                 sendbytes;
   struct sockaddr_in  servaddr;
   char                sendline[MAXLINE];
   char                recvline[MAXLINE];


	if (argc != 2 ) 
	   err_n_die("usage %s <server address>\n",argv[0]);

	// Create a new socket  - AF_INET AF(Address Family) 
	//                        SOCK_STREAM( Stream Socket)
	//                        0 == use TCP protocol
	if ( (sockfd = socket(AF_INET, SOCK_STREAM,0 )) < 0 )
		err_n_die("Error creating a socket\n");

	// initialise the server address by Zero out the address
    bzero(&servaddr, sizeof(servaddr));

    // Specify the Address Family as AF_INET
	servaddr.sin_family = AF_INET;

	// Specify the server port. htons(host to network, short)
	// convert local byte order to the network standard byte order.
	servaddr.sin_port   = htons(SERVER_PORT); 

    // convert the text IP address to a binary equivalent
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	  err_n_die("inet_pton error for %s", argv[1]); 

	// connect to the server
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0 )
	     err_n_die("Connect failed");

    // We're connected. Prepare the message.
	sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
	// Calculate the number of bytes we are about to send.
	sendbytes = strlen(sendline);

    /* Send the request -- making sure you send it all.

	This code is temperamental since it fails if only some of the bytes are sent.
	Normally you would want to retry unless the return value is -1
	*/

    if (write(sockfd, sendline, sendbytes) != sendbytes)
		err_n_die("write error");

	// the the recvline buffer to all zeros
	memset(recvline, 0, MAXLINE);

	// Now read the server's response
    while ( ( n = read(sockfd,recvline, MAXLINE -1 )) >0  )
	    printf("%s",recvline);

    if ( n < 0 )
		err_n_die("read error\n");

	return EXIT_SUCCESS;
}

// Variadic Function err_n_die
void err_n_die(const char *fmt, ...) {
   int errno_save;
   va_list    ap;

   // any system or library call can set errno, so we need to save it
   errno_save = errno;

   // print out the fmt+args to standard out
   va_start(ap, fmt);
   vfprintf(stdout,fmt,ap);
   fprintf(stdout,"\n");
   fflush(stdout);

   //
   if ( errno_save != 0 ) {
      fprintf(stdout,"(errno = %d) : %s\n",errno_save,strerror(errno_save));
	  fprintf(stdout, "\n");
	  fflush(stdout) ;
   }
   va_end(ap);
   exit(1);
}
