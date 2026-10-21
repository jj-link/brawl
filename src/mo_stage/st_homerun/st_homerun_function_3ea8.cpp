#include <types.h>
#pragma force_active on

extern "C" void fn_27_239E58(void*, s32, u8, f32, f32, f32);
extern "C" const f32 lbl_88_rodata_0;
extern "C" const f32 lbl_88_rodata_58;

extern "C" void fn_88_3EA8(void* arg0, s32 arg1, void* arg2) {
    f32 var_f31;
    if (arg1 != 0 && arg2 != NULL) {
        f32* p = (f32*)arg2;
        if (lbl_88_rodata_0 == p[3]) {
            var_f31 = lbl_88_rodata_58;
        } else {
            var_f31 = p[2] / p[3];
            if (var_f31 < lbl_88_rodata_0) {
                var_f31 = lbl_88_rodata_0;
            }
            if (var_f31 > lbl_88_rodata_58) {
                var_f31 = lbl_88_rodata_58;
            }
        }
        f32 p0 = p[0];
        f32 p1 = p[1];
        u8 b = *(u8*)((u8*)p + 0x10);
        fn_27_239E58(arg0, arg1, b, p0, p1, var_f31);
        if (lbl_88_rodata_58 == var_f31) {
            p[0] = p[1];
        }
    }
}
