#include <string.h>
#pragma force_active on

void fn_803D5064(const void *src, unsigned short *dest) {
    memset(dest, 0, 0x40);
    memcpy(dest, src, 0x36);
    *dest &= 0xFFFFC01F;
}
