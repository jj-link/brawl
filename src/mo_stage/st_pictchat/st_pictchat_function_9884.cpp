#include <types.h>
#pragma force_active on

extern "C" float fn_73_9884(const u8* self, u32 index)
{
    float* table = *(float**)(self + 0x6cc);
    return table[index];
}
