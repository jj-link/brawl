#include <types.h>
#pragma force_active on

struct FtPokeTable {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[9];
    void* entries[1];
};

extern "C" void* fn_116_23A98(const FtPokeTable* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
