#include "conversions.h"

char * UtoaBuiltinDiv8(uint8_t value, char *buffer)
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


char * UtoaBuiltinDiv16(uint16_t value, char *buffer)
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


char * UtoaBuiltinDiv32(uint32_t value, char *buffer)
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
