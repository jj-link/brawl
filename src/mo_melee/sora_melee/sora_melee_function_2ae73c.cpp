#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2ACD20(void* self, s32 a, s32 b);

extern "C" void fn_27_2AE73C(u8* self, s32* src) {
    s32 idx = fn_27_2ACD20(self, -1, -1);
    if (idx >= 0) {
        *(s32*)(self + idx * 12 + 0xC) = *src;
    }
}
