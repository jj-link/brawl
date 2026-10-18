#include <types.h>
#pragma force_active on

struct FalcoIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[3];
    void* entries[1];
};

extern "C" void* fn_108_10DB8(const FalcoIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
