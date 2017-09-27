#include "include.h"

namespace Math
{
  lli modExp(lli b, lli e, lli m)
  {
    lli remainder;
    lli x = 1;

    while (e != 0)
    {
      remainder = e % 2;
      e /= 2;

      if (remainder == 1)
        x = (x * b) % m;

      b = (b * b) % m;
    }

    return x;
  }
}
