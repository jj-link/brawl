#include <types.h>
#pragma force_active on

extern "C" void fn_115_A394(char* self, u32 index, float value) {
    float* arr = *(float**)(self + 0x14);
    arr[index] -= value;
}
