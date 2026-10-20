#include <types.h>
#pragma force_active on

extern "C" void fn_27_D1C8C(void* self)
{
    u32 value = *reinterpret_cast<u32*>(static_cast<char*>(self) + 8);
    value |= 0x2000;
    *reinterpret_cast<u32*>(static_cast<char*>(self) + 8) = value;
}
