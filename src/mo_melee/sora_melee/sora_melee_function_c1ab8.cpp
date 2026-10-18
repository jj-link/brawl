#include <types.h>
#pragma force_active on

extern const f32 lbl_27_rodata_EC0;

struct fn_27_C1AB8_obj {
    u8 pad0[0x8];
    f32 f8;
    f32 fc;
    f32 f10;
    u8 pad14[0x1c - 0x14];
    s16 s1c;
};

extern "C" void fn_27_C1AB8(fn_27_C1AB8_obj* p) {
    p->s1c = -1;
    p->f8 = lbl_27_rodata_EC0;
    p->f10 = lbl_27_rodata_EC0;
    p->fc = lbl_27_rodata_EC0;
}
