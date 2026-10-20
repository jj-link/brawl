#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_25EF4C(void* self, s32 n, s32 x);

extern "C" void fn_27_25EDCC(void* self, s32 n, s32* p) {
    s32 idx = fn_27_25EF4C(self, n - 1, -1);
    if (idx >= 0) {
        u8* base = (u8*)self;
        *(s32*)(base + idx * 12 + 12) = *p;
    }
}
