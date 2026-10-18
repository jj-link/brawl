#include <types.h>
#pragma force_active on

struct FtZeldaIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[7];
    void* entries[1];
};

extern "C" {
void* fn_104_24390(const FtZeldaIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
}
