#include <types.h>
#pragma force_active on

extern "C" {
struct fn_27_1A69DC_work {
    void *unk0;
    void *unk4;
    u32 unk8;
};

extern u8 lbl_27_data_33C40[];

void fn_27_1A69DC(fn_27_1A69DC_work *p) {
    u32 r0 = p->unk8;
    u8 *base = lbl_27_data_33C40;
    p->unk0 = base;
    p->unk4 = base + 0x48;
    p->unk8 = r0 & 1;
}
}
