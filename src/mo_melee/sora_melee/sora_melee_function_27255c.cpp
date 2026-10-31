#include <types.h>
#pragma force_active on

struct Owner {
    u8 pad[4];
    u8 unk4;
    u8 unk5;
};

extern Owner* lbl_27_bss_6148;

extern "C" void fn_27_271B14(Owner* self, void* p4, u32 a, u32 b, u32 c);

extern "C" void fn_27_27255C(Owner* self, void* p2, u32 a, u32 b, u32 c) {
    Owner* g = lbl_27_bss_6148;
    u32 x = a;
    if (self->unk5 == 0) {
        return;
    }
    if (g == 0) {
        return;
    }
    fn_27_271B14(g, p2, self->unk4, x, b);
}
