#include <types.h>
#pragma force_active on

extern "C" void* memset(void* dst, int value, unsigned long size);

extern "C" void fn_22_1BEC(u8* self) {
    *(u32*)(self + 0x44) = 0;
    *(u32*)(self + 0x48) = 0;
    *(u32*)(self + 0x4C) = 0;
    memset(self + 0x50, 0, 0x100);
    *(u32*)(self + 0x170) = 0;
}
