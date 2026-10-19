#include <types.h>
#pragma force_active on

extern const f32 lbl_103_rodata_8;

extern "C" void fn_103_A18C(void* self, s32 index, f32 divisor) {
    if (lbl_103_rodata_8 == divisor) {
        return;
    }
    f32* arr = *(f32**)((u8*)self + 0x14);
    arr[index] = arr[index] / divisor;
}
