#include <types.h>
#pragma force_active on

struct FF188Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_FF188(FF188Obj* p) {
    p->flags |= 0x80000;
}
}
