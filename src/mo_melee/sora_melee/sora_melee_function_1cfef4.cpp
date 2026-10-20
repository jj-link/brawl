#include <types.h>
#pragma force_active on

struct fn_27_1CFEF4_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_1CFEF4(fn_27_1CFEF4_Obj* p) {
    p->unk8 |= 0x00080000;
}
}
