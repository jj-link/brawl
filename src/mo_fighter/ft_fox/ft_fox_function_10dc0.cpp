#include <types.h>
#pragma force_active on

struct FoxIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[3];
    void* entries[1];
};

extern "C" void* fn_97_10DC0(const FoxIndefiniteParameters* object, void*, s32 selector) {
    return object->entries[selector - object->offset];
}
