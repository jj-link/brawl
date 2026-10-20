#include <types.h>
#pragma force_active on

struct fn_27_19F0B0_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_19F0B0(fn_27_19F0B0_Obj* p) {
    p->flags |= 0x400000;
}
