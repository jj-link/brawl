#include <types.h>
#pragma force_active on

extern "C" void fn_80025A1C(void* arg0) {
    u32 p = ((u32)arg0 + 0x6f) & 0xFFFFFFE0;
    u32 val = *(u32*)((u8*)arg0 + 8);
    u32 q = p + 0x20;
    u32 diff = val - q;
    *(u32*)((u8*)arg0 + 0x20) = p;
    *(u32*)(p + 0) = (u32)arg0;
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 8) = q;
    *(u32*)(p + 0xC) = 0;
    *(u16*)(p + 0x10) = 0;
    *(u8*)(p + 0x12) = 0;
    *(u8*)(p + 0x13) = 0;
    *(u32*)(p + 0x20) = (u32)arg0;
    *(u32*)(p + 0x24) = diff;
    *(u32*)(p + 0x28) = p;
    *(u32*)(p + 0x2C) = 0;
    *(u16*)(p + 0x30) = 0;
    *(u8*)(p + 0x32) = 0;
    *(u8*)(p + 0x33) = 0;
}
