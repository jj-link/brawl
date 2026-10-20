#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_CBD20(const void* p)
{
    return (reinterpret_cast<const u32*>(p)[2] >> 16) & 1;
}
