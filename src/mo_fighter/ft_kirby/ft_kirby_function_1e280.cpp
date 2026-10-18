#include <types.h>
#pragma force_active on

extern "C" u32* fn_96_1E280(u32* argument2, int argument3, u8* base)
{
    return reinterpret_cast<u32*>(reinterpret_cast<u8*>(argument2) + argument3 * 0x60 + 0xc);
}
