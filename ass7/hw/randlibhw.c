#include <immintrin.h>
#include "randlib.h"

/* Return a random value, using hardware operations.  */
unsigned long long rand64 (void)
{
  unsigned long long int x;
  while (! _rdrand64_step(&x))
    continue;
  return x;
}
