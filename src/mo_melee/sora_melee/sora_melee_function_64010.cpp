#include <types.h>
#pragma force_active on

extern const f32 lbl_27_rodata_8F0;
extern const f32 lbl_27_rodata_8F4;

struct fn_27_64010_obj {
    u8 pad0[0x24];
    s32 m24;
    u8 pad28[0x4];
    f32 m2c;
    f32 m30;
    f32 m34;
    u32 m38;
    u8 pad3c;
    u8 m3d;
};

extern "C" void fn_27_64010(fn_27_64010_obj *p) {
    p->m24 = -1;
    p->m2c = lbl_27_rodata_8F0;
    p->m30 = lbl_27_rodata_8F0;
    p->m34 = lbl_27_rodata_8F4;
    p->m38 = 0;
    p->m3d = 0;
}
