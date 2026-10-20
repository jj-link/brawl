#include <types.h>
#pragma force_active on

extern "C" void* fn_27_122B9C(void* object, s32 index)
{
    s32 bits = *reinterpret_cast<const s32*>(
        static_cast<const u8*>(object) + 8);
    s32 slot = (bits >> 26) + index;

    if (slot >= 16)
        slot -= 16;

    return static_cast<u8*>(object) + (slot << 4) + 12;
}
