#include <types.h>
#pragma force_active on

struct fn27_1A34B8_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_1A34B8(fn27_1A34B8_Obj* p) {
    p->unk8 |= 0x2;
}
}
