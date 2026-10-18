#include <types.h>
#pragma force_active on

struct FtPitTable {
    unsigned char prefix[0x18];
    s32 offset;
    unsigned char pad[0x58 - 0x1C];
    void* entries[1];
};

extern "C" void* fn_112_116C8(const FtPitTable* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
