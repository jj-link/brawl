#include <types.h>
#pragma force_active on

struct FtIndefiniteTable {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[2];
    void* entries[1];
};

extern "C" void* fn_94_202DC(const FtIndefiniteTable* object, void*, s32 selector) {
    return object->entries[selector - object->offset];
}
