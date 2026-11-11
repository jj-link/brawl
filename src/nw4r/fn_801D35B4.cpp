#include <types.h>

extern "C" f64 fn_80400B44(f64 base, f64 exponent);

extern const f32 lbl_805A3678;
extern const f32 lbl_805A3698;
extern const f64 lbl_805A36A0;
extern const f64 lbl_805A36A8;
extern const f64 lbl_805A36B0;
extern const f64 lbl_805A36B8;

#pragma force_active on
extern "C" s32 fn_801D35B4(f32 farg) {
    f32 var;
    if (farg > lbl_805A3678) {
        var = lbl_805A3678;
    } else {
        if (farg < lbl_805A3698) {
            var = lbl_805A3698;
        } else {
            var = farg;
        }
    }
    return (s32)(lbl_805A36A0 * fn_80400B44(lbl_805A36A8, lbl_805A36B0 * ((f64)var - lbl_805A36B8)));
}
