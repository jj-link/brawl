#include <types.h>
#pragma force_active on

struct fn_27_A1C4C_Obj {
    u8 pad_0[8];
    s32 unk8;
};

extern "C" {
u8* fn_27_A1C4C(fn_27_A1C4C_Obj* self, s32 idx) {
    s32 i = (self->unk8 >> 27) + idx;
    if (i >= 8) {
        i = i - 8;
    }
    return (u8*)self + i * 0x14 + 0xC;
}
}
