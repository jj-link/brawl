#pragma force_active on
#include <types.h>

extern f32 lbl_805A3640;
extern f32 lbl_805A3644;

struct FnObj1290 {
    unsigned char pad[0xB1];
    unsigned char flags;
    unsigned char pad2[0x62];
    f32 val1;
    f32 val2;
};

extern "C" void fn_801D1290(FnObj1290* obj, f32 f0, f32 f1) {
    f32 c0;
    f32 c1;

    c0 = lbl_805A3640;
    if (f0 > c0) {
        c0 = lbl_805A3640;
    } else {
        c0 = lbl_805A3644;
        if (f0 < c0) {
            c0 = lbl_805A3644;
        } else {
            c0 = f0;
        }
    }

    c1 = lbl_805A3640;
    if (f1 > c1) {
        c1 = lbl_805A3640;
    } else {
        c1 = lbl_805A3644;
        if (f1 < c1) {
            c1 = lbl_805A3644;
        } else {
            c1 = f1;
        }
    }

    if (c1 < lbl_805A3644) {
        if (c0 != obj->val2) {
            obj->val2 = c0;
            obj->flags |= 8;
        }
    } else if ((c1 != obj->val1) || (c0 != obj->val2)) {
        obj->val1 = c1;
        obj->val2 = c0;
        obj->flags |= 8;
    }
}
