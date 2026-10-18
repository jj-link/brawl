#include <types.h>
#pragma force_active on

struct Fn105Table {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[2];
    void* entries[1];
};

extern "C" void* fn_105_1EA54(const Fn105Table* object, void*, s32 selector) {
    return object->entries[selector - object->offset];
}
