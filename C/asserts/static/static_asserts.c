#include <assert.h>

enum {N = 5};
_Static_assert(N == 5, "N does not equal 5");
static_assert(sizeof(int) == 4, "Code relies on int being exactly 4 bytes");
static_assert(N > 10, "N is not greater than 10");  /* compiler error */
