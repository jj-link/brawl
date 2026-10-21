#include <types.h>
#pragma force_active on

extern "C" {
void fn_8014FE64(u32 rate);
}

extern u8* g_GameGlobal;

extern "C" void fn_8014FE64(u32 rate) {
    u8* p = *(u8**)(g_GameGlobal + 0x34);
    p[0x84] = (rate >> 8) & 0xFF;
    p[0x85] = rate;
}
