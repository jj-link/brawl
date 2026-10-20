#include <types.h>
#pragma force_active on

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A43F4(FnObj* obj) {
    obj->flags |= 0x2;
}
