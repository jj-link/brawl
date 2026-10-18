#include <types.h>
#pragma force_active on

extern "C" void fn_104_AA70(u8* work, u32 index, float value) {
    float* arr = *(float**)(work + 0x14);
    arr[index] += value;
}
