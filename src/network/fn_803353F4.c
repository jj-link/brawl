#include <types.h>
#pragma force_active on

extern void* (*lbl_805A0F5C)(void*, s32);

void* fn_803353F4(void* a0, s32 a1) {
    void* r = lbl_805A0F5C(a0, a1 + 0x20);
    if (r == 0) {
        return 0;
    }
    *(u32*)r = 0x4457434d;
    *(s32*)((char*)r + 4) = a1;
    return (char*)r + 0x20;
}
