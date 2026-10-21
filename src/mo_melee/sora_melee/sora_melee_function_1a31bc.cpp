#include <types.h>
#pragma force_active on

struct Obj1A31BC {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A31BC(Obj1A31BC* p) {
    p->flags &= ~0x00002000;
}
