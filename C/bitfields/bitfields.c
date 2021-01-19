#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <sys/types.h>


#define MAX_SIZE 10

#define DISP_PID 0x00000010

int main() {
   uint8_t  i,options ;

   
  for ( i=0; i< INT_MAX; i++) {
	  if (i == 4 )     options=DISP_PID;
	            else   options=1;

	  if (options & DISP_PID ) printf("Value is ====> %u\n",i);

  }

  return EXIT_SUCCESS;
}
