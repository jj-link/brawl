#include <types.h>
#pragma force_active on

struct FtYoshiIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[3];
    void* entries[1];
};

extern "C" void* fn_95_1D8CC(const FtYoshiIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
