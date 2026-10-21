#include <types.h>
#pragma force_active on

struct Obj1A3AE0 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A3AE0(Obj1A3AE0* p) {
    p->flags &= ~0x00000002;
}
