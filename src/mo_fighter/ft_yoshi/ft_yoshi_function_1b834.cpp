#include <types.h>
#pragma force_active on

struct YoshiParameterTable {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[4];
    void* entries[1];
};

extern "C" void* fn_95_1B834(const YoshiParameterTable* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
