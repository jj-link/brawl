#include <types.h>
#pragma force_active on

extern const f32 lbl_27_rodata_F00;

struct FnObj27 {
    u8 pad[0x60];
    f32 m60;
    f32 m64;
    f32 m68;
    u8 pad2[8];
    u32 m74;
};

extern "C" void fn_27_D3188(FnObj27* p) {
    u32 v = p->m74;
    v &= ~0x1Fu;
    p->m60 = lbl_27_rodata_F00;
    p->m64 = lbl_27_rodata_F00;
    p->m68 = lbl_27_rodata_F00;
    p->m74 = v;
}
