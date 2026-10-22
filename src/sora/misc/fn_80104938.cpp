#include <types.h>
#pragma force_active on

extern "C" void* memset(void* dst, int value, unsigned long size);
extern "C" void fn_800B96E8(void* p, int a);

extern "C" void fn_80104938(u8* s) {
    *(u32*)(s + 0) = 0;
    *(u32*)(s + 4) = 0;
    *(u32*)(s + 8) = 0;
    *(u32*)(s + 0xC) = 0;
    *(u32*)(s + 0x10) = 0;
    *(u32*)(s + 0x14) = 0;
    *(u32*)(s + 0x18) = 1;
    *(u32*)(s + 0x1C) = 0;
    *(u32*)(s + 0x20) = 1;
    *(u32*)(s + 0x24) = 3;
    *(u32*)(s + 0x28) = 0;
    *(u32*)(s + 0x2C) = 0;
    *(u8*)(s + 0x30) = 0;
    *(u32*)(s + 0xDC) = 0;
    fn_800B96E8(s + 0x34, 0);
    *(u32*)(s + 0xE0) = 0;
    *(u32*)(s + 0xE4) = 0;
    *(u32*)(s + 0xE8) = 0;
    memset(s + 0xEC, 0, 0x200);
    *(u32*)(s + 0x2EC) = 0;
    *(s32*)(s + 0x2F0) = -1;
    *(u32*)(s + 0x2F8) = 0;
    *(u8*)(s + 0x2FC) = 0;
}
