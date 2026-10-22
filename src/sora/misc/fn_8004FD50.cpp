#include <types.h>
#pragma force_active on

extern "C" {
void* fn_8004E588(void* ptr);
extern void* g_GameGlobal;
}

extern "C" s32 fn_8004FD50(void) {
    s32 count = 0;
    s32 i;
    for (i = 0; i < 0x66; i++) {
        s32 bit = i * 2;
        u32* words = (u32*)fn_8004E588(g_GameGlobal);
        u32 mask = 1 << (bit % 32);
        u32 v = words[bit / 32] & mask;
        if ((u32)(v != 0) == 1) {
            count++;
        }
    }
    return count;
}
