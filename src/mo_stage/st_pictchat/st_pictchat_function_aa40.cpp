#include <types.h>
#pragma force_active on

extern "C" void fn_73_AA40(void* self)
{
    u32 *ptr = (u32 *)((char *)self + 8);
    *ptr = *ptr | 0x00080000u;
}
