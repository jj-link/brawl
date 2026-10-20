#include <types.h>
#pragma force_active on

extern "C" void fn_50_6390(void* arg)
{
    u32* flags = reinterpret_cast<u32*>(arg) + 2;
    *flags &= ~0x02000000u;
}
