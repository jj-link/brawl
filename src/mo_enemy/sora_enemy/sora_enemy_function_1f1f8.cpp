#pragma force_active on
#include <types.h>

extern "C" bool fn_41_1AE7C(void* p);
extern float lbl_41_rodata_C9C;

extern "C" s32 fn_41_1F1F8(u8* self) {
    s32 r = -1;
    s32 t;
    if (fn_41_1AE7C(self) == 1) return -1;
    t = *(s32*)(self + 0x8);
    if (t != 0x15 && t != 0x16) return -1;
    if (*(s32*)(self + 0x90) == 0) return -1;
    if (*(f32*)(self + 0x4C) >= lbl_41_rodata_C9C) {
        if (*(f32*)(self + 0x98) > lbl_41_rodata_C9C) {
            r = 2;
        } else if (*(f32*)(self + 0x98) < lbl_41_rodata_C9C) {
            r = 3;
        }
    } else {
        if (*(f32*)(self + 0x98) > lbl_41_rodata_C9C) {
            r = 3;
        } else if (*(f32*)(self + 0x98) < lbl_41_rodata_C9C) {
            r = 2;
        }
    }
    return r;
}
