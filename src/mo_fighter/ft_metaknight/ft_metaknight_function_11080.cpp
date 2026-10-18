#include <types.h>
#pragma force_active on

extern "C" void* fn_111_11080(u8* self, s32 unused, s32 index) {
    s32 off = (index - *(s32*)(self + 0x18)) * 4;
    return *(void**)(self + off + 0x24);
}
