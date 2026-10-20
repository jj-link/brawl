#include <types.h>
#pragma force_active on

extern "C" void fn_27_CF9EC(u8* p)
{
    u32* flags = (u32*)(p + 8);
    *flags |= 0x00400000;
}
