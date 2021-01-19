#include <stdlib.h>

void Test(void *ptr)
{
	free(ptr);
	free(ptr);
}
