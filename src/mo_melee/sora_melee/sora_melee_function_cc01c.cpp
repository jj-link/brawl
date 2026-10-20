#include <types.h>
#pragma force_active on

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_CC01C(fn27Obj* p) {
    p->flags &= ~0x02000000;
}
