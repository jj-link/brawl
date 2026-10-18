#include <types.h>
#pragma force_active on

struct Fn112Table {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[11];
    void* entries[1];
};

extern "C" void* fn_112_16AFC(const Fn112Table* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
