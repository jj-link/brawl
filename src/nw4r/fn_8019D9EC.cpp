#include <types.h>
#include <nw4r/math.h>
#pragma force_active on

extern "C" double fn_80400B3C(float, double);
extern "C" const float lbl_805A32F0;

extern "C" f32 fn_8019D9EC(f32 farg0, f32 farg1, f32 farg2) {
    f32 temp_f31 = farg1 - farg0;
    if (farg2 >= lbl_805A32F0) {
        return (f32)fn_80400B3C(farg2, temp_f31);
    }
    f32 temp_f1 = (f32)fn_80400B3C(farg2 + temp_f31, temp_f31);
    return temp_f1 + nw4r::math::FSelect(temp_f1, lbl_805A32F0, temp_f31);
}
