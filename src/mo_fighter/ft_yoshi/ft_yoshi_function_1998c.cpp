#include <types.h>
#pragma force_active on

struct FnTableObject {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[2];
    void* entries[1];
};

extern "C" void* fn_95_1998C(const FnTableObject* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
