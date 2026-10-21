#include <types.h>

extern f32 lbl_805A3640;
extern f32 lbl_805A3644;

struct FnObj110 {
    char pad[0xB1];
    unsigned char flags;
    char pad2[0x110 - 0xB2];
    f32 unk110;
};

#pragma force_active on
extern "C" void fn_801D124C(FnObj110* obj, f32 val) {
    f32 v;
    if (val > lbl_805A3640) {
        v = lbl_805A3640;
    } else if (val < lbl_805A3644) {
        v = lbl_805A3644;
    } else {
        v = val;
    }
    if (v != obj->unk110) {
        obj->unk110 = v;
        obj->flags |= 8;
    }
}
