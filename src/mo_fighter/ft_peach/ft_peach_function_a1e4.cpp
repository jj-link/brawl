#include <types.h>
#pragma force_active on

extern "C" void fn_103_A1E4(void* self, s32 index, f32 value) {
    f32* arr = *(f32**)((char*)self + 0x14);
    arr[index] += value;
}
