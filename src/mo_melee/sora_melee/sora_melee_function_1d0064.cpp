#include <types.h>
#pragma force_active on

struct fn_27_1D0064_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1D0064(fn_27_1D0064_obj* p) {
    p->flags |= 0x400000;
}
