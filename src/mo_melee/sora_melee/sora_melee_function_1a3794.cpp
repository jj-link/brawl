#include <types.h>
#pragma force_active on

struct fn_27_1A3794_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1A3794(fn_27_1A3794_Obj *p) {
    return (s32)((p->unk8 << 10) & 0xFFE00000) >> 22;
}
}
