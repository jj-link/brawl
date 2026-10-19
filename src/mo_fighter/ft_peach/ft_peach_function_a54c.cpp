#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
int fn_103_A5A4(void);

f32 fn_103_A54C(u8* base, s32 unused, s32 i, s32 j) {
    s32 k = fn_103_A5A4();
    u8* p = base;
    p += k * 0x90;
    p += i * 4;
    f32* arr = *reinterpret_cast<f32**>(p - 0x3E70);
    return arr[j];
}
}
