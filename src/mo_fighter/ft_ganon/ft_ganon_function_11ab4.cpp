#include <types.h>
#pragma force_active on

struct FnIndexedTable {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[4];
    void* entries[1];
};

extern "C" void* fn_109_11AB4(const FnIndexedTable* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
