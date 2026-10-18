#include <types.h>
#pragma force_active on

struct FtPikminParameters {
    unsigned char prefix[0x18];
    s32 offset;
};

extern "C" void* fn_113_2A070(const FtPikminParameters* object, void*, s32 selector) {
    s32 index = selector - object->offset;
    void* const* p = (void* const*)((char*)object + index * 4);
    return p[0x4c / 4];
}
