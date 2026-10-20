#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2ADA28(void* self, s32 a, s32 b);

extern "C" void fn_27_2AF0E4(void* self, s32* src) {
    s32 idx = fn_27_2ADA28(self, -1, -1);
    if (idx >= 0) {
        *(s32*)((u8*)self + idx * 12 + 0x10) = *src;
    }
}
