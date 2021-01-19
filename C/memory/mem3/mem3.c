#include <stdlib.h>

void test(void *ptr)
{
  free(ptr);
  free(ptr);
}
