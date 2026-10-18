#include <types.h>
#pragma force_active on

extern "C" void fn_79_17CC(u8 *base, u8 arg1, u32 arg2, float arg3)
{
    base[0x184] = arg1;
    *reinterpret_cast<u32 *>(base + 0x188) = arg2;
    *reinterpret_cast<f32 *>(base + 0x18c) = arg3;
}
