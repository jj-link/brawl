#include <types.h>
#pragma force_active on

extern "C" s32 fn_80056780(void);
extern void* g_GameGlobal;

extern "C" void fn_80052880(void* unused, u32 flag) {
    s32 idx = fn_80056780();
    u8* base = *(u8**)((u8*)g_GameGlobal + 0x24) + 0x842;
    u16 v = ((u16*)base)[idx];

    if (flag == 1) {
        v = v | 0x4000;
    } else {
        v = v & ~0x4000;
    }

    *(u16*)(base + idx * 2) = v;
}
