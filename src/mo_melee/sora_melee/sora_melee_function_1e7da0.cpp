#include <types.h>
#pragma force_active on

struct Obj1E7DA0 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1E7DA0(Obj1E7DA0* p) {
    p->flags &= ~0x02000000;
}
