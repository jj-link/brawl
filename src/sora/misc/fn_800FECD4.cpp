#include <types.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_804091A8[];
extern float lbl_805A2748;
extern float lbl_805A274C;
extern float lbl_805A2750;
extern float lbl_805A2754;

s32 fn_800FEE4C(void*, void*, u8);
void setFrameVisible__8MuObjectFf(void*, float);
}

extern "C" void fn_800FECD4(void* arg0, s32 arg1) {
    s32 off = arg1 * 4 - arg1;
    s32 idx = lbl_804091A8[(unsigned int)arg1 * 3];
    const unsigned char* p = lbl_804091A8 + off;
    s32 result = fn_800FEE4C(
        arg0,
        *(void**)((char*)arg0 + p[1] * 4 + 0xF0),
        p[2]
    );

    float frame;
    if (arg1 != 2) {
        if (result < 6) {
            frame = lbl_805A2748;
        } else if (result == 6) {
            frame = lbl_805A274C;
        } else {
            frame = lbl_805A2750;
        }
    } else {
        frame = lbl_805A2754;
    }

    setFrameVisible__8MuObjectFf(
        *(void**)((char*)arg0 + idx * 4 + 4),
        frame
    );
}
