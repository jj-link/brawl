#include <types.h>
#pragma force_active on

extern "C" void fn_27_C9E08(u8* p)
{
    u32* flags = (u32*)(p + 8);
    *flags &= 0xFDFFFFFF;
}
