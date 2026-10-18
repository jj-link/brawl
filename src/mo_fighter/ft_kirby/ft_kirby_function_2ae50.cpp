#include <types.h>
#pragma force_active on

struct KirbyIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[2];
    void* entries[1];
};

extern "C" void* fn_96_2AE50(const KirbyIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
