#include <types.h>
#pragma force_active on

struct IndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[22];
    void* entries[1];
};

extern "C" void* fn_121_1494C(const IndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
