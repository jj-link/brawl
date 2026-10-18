#include <types.h>
#pragma force_active on

struct Fn95TableObject {
    s32 prefix[6];
    s32 offset;
    s32 reserved[6];
    void* entries[1];
};

extern "C" void* fn_95_17740(const Fn95TableObject* object, void*, s32 selector) {
    return object->entries[selector - object->offset];
}
