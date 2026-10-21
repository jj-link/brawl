#include <types.h>
#pragma force_active on

extern "C" void fn_27_239BDC(void*, s32, void*, void*, u8, f32);
extern "C" const f32 lbl_88_rodata_0;
extern "C" const f32 lbl_88_rodata_58;

extern "C" void fn_88_3DDC(void* arg0, s32 arg1, void* arg2) {
    f32 var_f31;
    if (arg1 != 0 && arg2 != NULL) {
        f32* p = (f32*)arg2;
        if (lbl_88_rodata_0 == p[7]) {
            var_f31 = lbl_88_rodata_58;
        } else {
            var_f31 = p[6] / p[7];
            if (var_f31 < lbl_88_rodata_0) {
                var_f31 = lbl_88_rodata_0;
            }
            if (var_f31 > lbl_88_rodata_58) {
                var_f31 = lbl_88_rodata_58;
            }
        }
        u8 b = *(u8*)((u8*)arg2 + 0x20);
        fn_27_239BDC(arg0, arg1, arg2, (void*)((u8*)arg2 + 0xc), b, var_f31);
        if (lbl_88_rodata_58 == var_f31) {
            p[0] = p[3];
            p[1] = p[4];
            p[2] = p[5];
        }
    }
}
