#include <types.h>
#pragma force_active on

struct Obj1A5A5C {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A5A5C(Obj1A5A5C* obj) {
    obj->flags &= ~0x2u;
}
