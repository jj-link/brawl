#include <ms/ms_char_writer.h>
#include <types.h>
#pragma force_active on

extern "C" s32 fn_800717D4(ms::CharWriter* arg0, f32* arg1, s32 arg2, s32 arg3);
extern f32 lbl_805A1AA0;

extern "C" void fn_80071C38(ms::CharWriter* arg0, f32* arg1, s32 arg2, s32 arg3) {
    f32 buf[4];
    s32 r30;
    s32 r31;
    s32 n;
    f32 zero;

    zero = 0.0f;
    r31 = arg2;
    r30 = arg3;
    arg1[0] = zero;
    arg1[2] = zero;
    arg1[1] = zero;
    arg1[3] = zero;
    arg0->SetCursor(zero, zero);
    zero = lbl_805A1AA0;
    do {
        buf[0] = zero;
        buf[1] = zero;
        buf[2] = zero;
        buf[3] = zero;
        n = fn_800717D4(arg0, buf, r31, r30);
        f32 value = buf[0];
        r31 += n;
        r30 -= n;
        arg1[0] = (arg1[0] > value) ? value : arg1[0];
        arg1[1] = (arg1[1] > buf[1]) ? buf[1] : arg1[1];
        arg1[2] = (arg1[2] < buf[2]) ? buf[2] : arg1[2];
        arg1[3] = (arg1[3] < buf[3]) ? buf[3] : arg1[3];
    } while (r30 > 0);
}
