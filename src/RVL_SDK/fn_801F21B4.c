#pragma force_active on
#include <types.h>

extern f32 lbl_805A37E8;
extern f32 lbl_805A3800;
extern f32 lbl_805A3814;

void fn_801F21B4(void* arg0, s32 arg1, f32 farg0, f32 farg1) {
    f32* out = (f32*)arg0;
    s32 mode = arg1;
    f32 v3;
    f32 v4;
    f32 v5;

    if (farg0 < lbl_805A37E8) {
        mode = 0;
    }
    if (farg1 <= lbl_805A37E8 || farg1 >= lbl_805A3800) {
        mode = 0;
    }
    switch (mode) {
    case 1:
        v5 = lbl_805A3800;
        v3 = (lbl_805A3800 - farg1) / (farg1 * farg0);
        v4 = lbl_805A37E8;
        break;
    case 2:
        v5 = lbl_805A3800;
        v3 = (lbl_805A3814 * (lbl_805A3800 - farg1)) / (farg1 * farg0);
        v4 = (lbl_805A3814 * (lbl_805A3800 - farg1)) / (farg0 * (farg1 * farg0));
        break;
    case 3:
        v5 = lbl_805A3800;
        v3 = lbl_805A37E8;
        v4 = (lbl_805A3800 - farg1) / (farg0 * (farg1 * farg0));
        break;
    case 0:
    default:
        v5 = lbl_805A3800;
        v3 = lbl_805A37E8;
        v4 = v3;
        break;
    }
    out[7] = v5;
    out[8] = v3;
    out[9] = v4;
}
