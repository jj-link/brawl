#include <types.h>
#pragma force_active on

extern "C" float fn_79_4094(void* self, u32 index) {
    float* table = *(float**)((u8*)self + 0x156c);
    return table[index];
}
