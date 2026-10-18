#include <types.h>
#pragma force_active on

struct ParamTable {
    unsigned char prefix[0x18];
    s32 offset;
    unsigned char pad[0x40];
    void* entries[1];
};

extern "C" void* fn_105_1BF44(const ParamTable* object, void*, s32 selector, s32) {
    return object->entries[selector - object->offset];
}
