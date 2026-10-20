#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2919A4(const void* p) {
    u32 value = *reinterpret_cast<const u32*>(
        reinterpret_cast<const unsigned char*>(p) + 8);
    value = (value << 4) & 0xF8000000u;
    return static_cast<s32>(value) >> 28;
}
