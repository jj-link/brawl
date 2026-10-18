#include <types.h>
#pragma force_active on

struct FtSonicTable {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[12];
    void* entries[1];
};

extern "C" void* fn_123_141FC(const FtSonicTable* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
