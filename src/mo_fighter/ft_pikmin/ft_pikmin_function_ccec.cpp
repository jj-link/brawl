#include <types.h>
#pragma force_active on

extern "C" void fn_113_CCEC(void* self, u32 index, float value) {
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] += value;
}
