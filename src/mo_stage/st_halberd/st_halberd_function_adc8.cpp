#include <types.h>
#pragma force_active on

extern "C" void fn_57_ADC8(void* arg)
{
    u32* ptr = (u32*)((u8*)arg + 8);
    *ptr &= ~0x00400000;
}
