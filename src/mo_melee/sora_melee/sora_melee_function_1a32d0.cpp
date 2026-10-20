#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_1A32D0(const void* obj) {
    u32 val = *(const u32*)((const u8*)obj + 8);
    return (val >> 1) & 1;
}
