#include <types.h>
#pragma force_active on

struct FnParameterTable {
    unsigned char prefix[0x18];
    s32 offset;
    unsigned char pad[0x74 - 0x1C];
    void* entries[1];
};

extern "C" void* fn_93_14900(const FnParameterTable* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
