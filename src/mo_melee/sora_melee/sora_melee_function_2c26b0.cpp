#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2C20E8(s32* a, s32 b, s32 c);

extern "C" void fn_27_2C26B0(s32* base, s32 index, s32* value) {
    s32 i = fn_27_2C20E8(base, index - 1, -1);
    if (i >= 0) {
        base[i * 3 + 3] = *value;
    }
}
