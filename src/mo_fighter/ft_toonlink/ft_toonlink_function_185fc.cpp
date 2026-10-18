#include <types.h>
#pragma force_active on

struct FighterTableParameters {
    unsigned char prefix[0x18];
    s32 offset;
    u32 reserved[6];
    void* entries[1];
};

extern "C" void* fn_121_185FC(const FighterTableParameters* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
