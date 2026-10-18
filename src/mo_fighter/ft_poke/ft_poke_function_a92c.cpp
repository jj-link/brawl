#include <types.h>
#pragma force_active on

extern "C" void fn_116_A92C(u8* self, s32 value, u32 index) {
    s32* arr = *(s32**)(self + 0xc);
    arr[index] *= value;
}
