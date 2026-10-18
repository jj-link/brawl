#include <types.h>
#pragma force_active on

struct PokeIndefiniteParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[3];
    void* entries[1];
};

extern "C" void* fn_116_26634(const PokeIndefiniteParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
