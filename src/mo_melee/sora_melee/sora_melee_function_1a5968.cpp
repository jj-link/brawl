#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_1A5968(const void* p) {
    u32 v = *(const u32*)((const u8*)p + 8);
    return (v >> 16) & 1;
}
