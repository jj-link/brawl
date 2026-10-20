#include <types.h>
#pragma force_active on

extern "C" void fn_48_BC64(void* self)
{
    s32* p = (s32*)((u8*)self + 0x8);
    *p |= 0x2000;
}
