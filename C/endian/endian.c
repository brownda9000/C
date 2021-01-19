#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

int send_bytes_over_network(uint8_t *bytes, int nbytes) {
   return 0;
}

int main() {
   int x = 0x01234567;

   uint8_t buffer[256];

   memcpy(buffer, &x , sizeof(int));
   printf("INT_MAX     :   %d\n", INT_MAX);   
   for (int i=0; i < sizeof(int); i++ ) {
      printf("%02hhX ", buffer[i]);
	}

    printf("\n");

   send_bytes_over_network(buffer, sizeof(buffer));
}
