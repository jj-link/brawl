#include <types.h>
#pragma force_active on

extern "C" void* fn_125_10CD8(unsigned char* object, void*, s32 selector, s32) {
    s32 offset = *(s32*)(object + 0x18);
    return *(void**)(object + (selector - offset) * 4 + 0x28);
}
