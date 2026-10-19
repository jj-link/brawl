#include <types.h>
#pragma force_active on

extern "C" u32 fn_126_74F4(const void* self, u32 mask, u32 index) {
    const u32* flags = *(const u32* const*)((const char*)self + 0x1c);
    return (flags[index] & mask) != 0;
}
