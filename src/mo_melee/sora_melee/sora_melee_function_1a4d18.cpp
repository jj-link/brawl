#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A4D18(u8* self)
{
    u32* flags = (u32*)(self + 8);
    *flags |= 0x10000;
}
