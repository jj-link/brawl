#include <types.h>
#include <revolution/OS/OSMutex.h>
#pragma force_active on

struct PoolFlags {
    u8 high : 1;
    u8 rest : 7;
};

extern "C" void* fn_80025B78(void* self, const char* name, void* base, u32 size) {
    u8* p = (u8*)self;
    *(const char**)(p + 0x00) = name;
    p[0x10] = 0;
    ((PoolFlags*)(p + 0x11))->high = 0;
    p[0x12] = 0;
    *(u16*)(p + 0x14) = 0;
    *(u16*)(p + 0x16) = 0;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x1C) = 0;
    p[0x24] = 0;
    OSInitMutex((OSMutex*)(p + 0x28));
    u32 end = (u32)base + size;
    u8* block = (u8*)(((u32)p + 0x6F) & ~0x1F);
    *(void**)(p + 0x04) = base;
    u8* next = block + 0x20;
    *(u32*)(p + 0x08) = end;
    *(u32*)(p + 0x0C) = size;
    *(u8**)(p + 0x20) = block;
    *(void**)(block + 0x00) = self;
    *(u32*)(block + 0x04) = 0;
    *(u8**)(block + 0x08) = next;
    *(u32*)(block + 0x0C) = 0;
    *(u16*)(block + 0x10) = 0;
    block[0x12] = 0;
    block[0x13] = 0;
    *(void**)(block + 0x20) = self;
    *(u32*)(block + 0x24) = end - (u32)next;
    *(u8**)(block + 0x28) = block;
    *(u32*)(block + 0x2C) = 0;
    *(u16*)(block + 0x30) = 0;
    block[0x32] = 0;
    block[0x33] = 0;
    return self;
}
