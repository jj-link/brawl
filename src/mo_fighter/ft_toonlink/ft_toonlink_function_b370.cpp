#include <types.h>
#pragma force_active on

extern "C" void fn_121_B370(void* self, s32 value, u32 index) {
    s32* arr = *(s32**)((char*)self + 0xc);
    arr[index] -= value;
}
