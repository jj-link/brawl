#include <types.h>
#pragma force_active on

struct fn27Obj {
    u8 pad[0x18];
    s32 unk18;
};

extern "C" void* fn_27_1C49DC(fn27Obj* obj, s32 idx)
{
    s32 k = (obj->unk18 >> 28) + idx;
    if (k >= 5) {
        k -= 5;
    }
    return (u8*)obj + k * 12 + 0x1c;
}
