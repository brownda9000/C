#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>


size_t fetchedData(char* buffer, size_t itemsize, size_t nitems, void *ignorethis ) {
    size_t bytes = itemsize * nitems;
    int     line = 1;

	printf("New data chunk ( %zu bytes)\n", bytes);
    for (int i=0; i < bytes; i++ ) {
	   if ( buffer[i] == "\n" ) 
		   printf("\n");
	   else
		  // printf("%c", buffer[i]);
		  // process the buffer
		  line++;
	}
	return bytes;
}

int main (void) {
   CURL *curl = curl_easy_init();

   if (!curl) {
      fprintf(stderr, "init failed\n");
	  return EXIT_FAILURE;
   }

   // set curl options
   curl_easy_setopt(curl, CURLOPT_URL , "https://www.bbc.co.uk");
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION , fetchedData);

   // perform out action
   CURLcode result = curl_easy_perform(curl);
   if (result != CURLE_OK) {
      fprintf(stderr, "ERROR: download issue %s \n", curl_easy_strerror(result));
   }
   curl_easy_cleanup(curl);
   return EXIT_SUCCESS;
}
