#include <types.h>
#pragma force_active on

struct WarioTableParameters {
    unsigned char prefix[0x18];
    s32 offset;
    unsigned char gap[0xbc - 0x1c];
    void* entries[1];
};

extern "C" void* fn_110_12DE8(const WarioTableParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
