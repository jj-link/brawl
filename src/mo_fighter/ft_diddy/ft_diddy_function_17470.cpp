#include <types.h>
#pragma force_active on

struct FtIndexedTable {
    unsigned char prefix[0x18];
    s32 offset;
};

extern "C" void* fn_115_17470(const FtIndexedTable* object, void*, s32 selector, s32) {
    const s32* base = (const s32*)object;
    return *(void**)((const char*)(base + (selector - object->offset)) + 0x5c);
}
