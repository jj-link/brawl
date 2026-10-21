#include <types.h>
#pragma force_active on

extern f32 lbl_805A3640;
extern f32 lbl_805A3644;

struct FnObj14B4 {
    char pad0[0xB1];
    unsigned char unkB1;
    char pad1[0xCC - 0xB2];
    f32 unkCC;
};

extern "C" void fn_801D14B4(FnObj14B4* arg0, f32 farg0) {
    f32 temp_f0;
    f32 var_f2;

    var_f2 = lbl_805A3640;
    temp_f0 = farg0 + var_f2;
    if (temp_f0 > var_f2) {
        var_f2 = lbl_805A3640;
    } else {
        var_f2 = lbl_805A3644;
        if (temp_f0 < var_f2) {
            var_f2 = lbl_805A3644;
        } else {
            var_f2 = temp_f0;
        }
    }
    if (var_f2 != arg0->unkCC) {
        arg0->unkCC = var_f2;
        arg0->unkB1 = (u8) (arg0->unkB1 | 0x10);
    }
}
