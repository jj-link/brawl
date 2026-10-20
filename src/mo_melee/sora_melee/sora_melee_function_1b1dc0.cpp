#include <types.h>
#pragma force_active on

struct fn_27_1B1DC0_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8_a : 12;
    s32 unk8_b : 6;
    u32 unk8_c : 14;
};

extern "C" {
s32 fn_27_1B1DC0(fn_27_1B1DC0_Obj* p) {
    return p->unk8_b;
}
}
