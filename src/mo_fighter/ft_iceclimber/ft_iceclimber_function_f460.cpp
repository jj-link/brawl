#include <types.h>
#pragma force_active on

extern "C" void fn_105_F460(char* obj, u8 value)
{
    char* base = obj + 0x10000;
    base[0x7a10] = (char)value;
}
