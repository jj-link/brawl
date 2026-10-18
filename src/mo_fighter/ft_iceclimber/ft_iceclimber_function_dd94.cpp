#include <types.h>
#pragma force_active on

extern "C" void fn_105_DD94(u8* self, u32 index) {
    s32* arr = *(s32**)(self + 0xc);
    arr[index]--;
}
