#include <types.h>
#pragma force_active on

struct FnObj27 {
    u8 pad_0[8];
    u32 flags_8;
};

extern "C" void fn_27_1A2DAC(FnObj27* p) {
    p->flags_8 &= ~0x02000000;
}
