#include <types.h>
#pragma force_active on

extern "C" void fn_96_F4E8(u8* self, u32 index, float value) {
    float* arr = *(float**)(self + 0x14);
    arr[index] += value;
}
