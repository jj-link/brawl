#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_805A367C;
extern float lbl_805A3680;
extern float lbl_805A3694;
extern float lbl_805A3698;
extern void* lbl_80466D50[];

float fn_801D3520(s32* arg0, float farg0) {
    float var_f0;
    float var_f3;
    float temp_f0;

    var_f0 = lbl_805A367C;
    if (farg0 > var_f0) {
        var_f0 = lbl_805A367C;
    } else if (farg0 < lbl_805A3698) {
        var_f0 = lbl_805A3698;
    } else {
        var_f0 = farg0;
    }

    farg0 = var_f0 * lbl_805A3680;
    temp_f0 = ((float*)lbl_80466D50[*arg0])[
        (s32)(lbl_805A3680 + lbl_805A3694 * farg0)];
    var_f3 = lbl_805A367C;

    if (temp_f0 > var_f3) {
        var_f3 = lbl_805A367C;
    } else if (temp_f0 < lbl_805A3698) {
        var_f3 = lbl_805A3698;
    } else {
        var_f3 = temp_f0;
    }
    return var_f3;
}
}
