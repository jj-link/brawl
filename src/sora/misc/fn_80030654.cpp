#pragma force_active on
#include <types.h>

extern "C" void* __ct__9gfArchiveFv(void*);

extern "C" void* fn_80030654(void* self) {
    *(u32*)((u8*)self + 0x8) = 0;
    __ct__9gfArchiveFv((u8*)self + 0xC);
    *(u32*)((u8*)self + 0xF0) = 0;
    *(u32*)((u8*)self + 0xA8) = 6;
    *(u32*)((u8*)self + 0xAC) = 0;
    *(u32*)((u8*)self + 0xB0) = 0;
    *(u32*)self = 0;
    *(u32*)((u8*)self + 0x4) = 0;
    *(u32*)((u8*)self + 0xA0) = 0;
    *(u32*)((u8*)self + 0xA4) = 0;
    *(u32*)((u8*)self + 0x8C) = 0;
    *(u32*)((u8*)self + 0x90) = 0;
    *(u32*)((u8*)self + 0x94) = 0;
    *(u32*)((u8*)self + 0x9C) = 0;
    *(u8*)((u8*)self + 0x98) = 0;
    return self;
}
