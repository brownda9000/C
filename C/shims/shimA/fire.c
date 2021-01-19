#define _GNU_SOURCE

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
//#include <pthread.h>
#include <dlfcn.h>

#define BUFFER_LEN 4096

int connect(int sockfd, const struct sockaddr *addr , socklen_t addrlen) {
    int (*original_connect)(int ,const struct sockaddr* , socklen_t) = NULL;
    original_connect = dlsym(RTLD_NEXT,"connect");

    struct sockaddr_in *myaddr = (struct sockaddr_in*)addr;
    struct sockaddr_in6 *myaddr6 = (struct sockaddr_in6*)addr;


    char *fam = "OTHER";
    if (addr->sa_family == AF_INET) fam = "AF_INET";
    if (addr->sa_family == AF_INET6) fam = "AF_INET6";

    char address_str[BUFFER_LEN] = {0};
    if (addr->sa_family == AF_INET) { 
        inet_ntop(addr->sa_family, &(myaddr->sin_addr.s_addr), address_str,BUFFER_LEN);
    }
    else if (addr->sa_family == AF_INET6) {
        inet_ntop(addr->sa_family, &(myaddr6->sin6_addr.s6_addr), address_str,BUFFER_LEN);
    }

    char host[BUFFER_LEN]   = {0};
    char server[BUFFER_LEN] = {0};
    //getnameinfo(addr, addrlen, host, BUFFER_LEN, server, BUFFER_LEN, 0);
    //getnameinfo(addr, addrlen, host, BUFFER_LEN, NULL, 0, NI_NUMERICSERV | NI_NUMERICHOST );
    getnameinfo(addr, addrlen, host, BUFFER_LEN, server, BUFFER_LEN,   );
    printf("%s %s %s\n", host, fam, address_str);
    return original_connect(sockfd, addr, addrlen);
    // errno = ECONNREFUSED;
    // return -1;
}