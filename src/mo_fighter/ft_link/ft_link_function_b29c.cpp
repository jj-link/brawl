#include <types.h>
#pragma force_active on

extern "C" void fn_93_B29C(u8* self, u32 index, float scale) {
    float* arr = *(float**)(self + 0x14);
    arr[index] *= scale;
}
