#include <types.h>
#pragma force_active on
void fn_80399D04(u64 input, char *output) {
 char *buf = output;
 u64 value = input;
 int i;
 for (i = 15; i >= 0; i--) {
  buf[i] = value % 10 + '0';
  value /= 10;
 }
 buf[16] = 0;
}