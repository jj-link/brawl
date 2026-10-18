#include <types.h>
#pragma force_active on

extern "C" {
void fn_24_12C4(u8* p) {
    *(u32*)(p + 0x50) = 0;
    p[0x2c] &= ~0x02;
}
}
