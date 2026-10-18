#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_1CA68(u8* p)
{
    u32 b = (p[0x165] >> 1) & 1;
    return (u32)(-b | b) >> 31;
}
