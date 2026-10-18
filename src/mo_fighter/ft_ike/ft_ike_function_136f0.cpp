#include <types.h>
#pragma force_active on

struct IkeIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[2];
    void* entries[1];
};

extern "C" void* fn_119_136F0(const IkeIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
