#include <stdio.h>

#include "include/library.h"

void my_library_function(void) {
  printf("%s  %s:%d: Static Library \n", __func__, __FILE__, __LINE__);
}
