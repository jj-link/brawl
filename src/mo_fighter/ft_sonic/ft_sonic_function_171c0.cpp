#include <types.h>
#pragma force_active on

struct SonicIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    unsigned char pad[0x50 - 0x1C];
    void* entries[1];
};

extern "C" void* fn_123_171C0(const SonicIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
