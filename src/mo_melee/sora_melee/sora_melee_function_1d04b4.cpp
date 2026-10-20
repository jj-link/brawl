#include <types.h>
#pragma force_active on

struct fn27Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" void fn_27_1D04B4(fn27Obj* p) {
    p->flags |= 0x400;
}
