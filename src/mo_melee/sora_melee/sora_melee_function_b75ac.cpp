#include <types.h>
#pragma force_active on

struct soObj {
    u8 pad0[0x10];
    float f10;
    float f14;
    u8 pad18[0xC];
    float f24;
};

extern const float lbl_27_rodata_E28;

extern "C" {
void fn_27_B75AC(soObj* p) {
    float v = lbl_27_rodata_E28;
    p->f10 = v;
    p->f14 = v;
    p->f24 = v;
}
}
