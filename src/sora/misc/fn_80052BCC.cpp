#include <types.h>
#pragma force_active on

extern "C" int fn_8005680C(void);
extern void* g_GameGlobal;

struct S {
    u8 pad[0xD58];
    u16 flags[0x400];
};

extern "C" void fn_80052BCC(void* unused, u32 value) {
    s32 idx = fn_8005680C();
    S* p = *(S**)((u8*)g_GameGlobal + 0x24);
    u16* arr = p->flags;
    u16 v = arr[idx];
    if (value > 0x3E8U) {
        value = 0x3E7;
    }
    ((s16*)arr)[idx] = (s16)(value | (v & 0xF000));
}
