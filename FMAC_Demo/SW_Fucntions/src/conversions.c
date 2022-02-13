#include "conversions.h"

char * UtoaBuiltinDiv(uint16_t value, char *buffer)
{
   buffer += 11;
   *--buffer = 0;
   do
   {
      *--buffer = value % 10 + '0';
      value /= 10;
   }
   while (value != 0);
   return buffer;
}
