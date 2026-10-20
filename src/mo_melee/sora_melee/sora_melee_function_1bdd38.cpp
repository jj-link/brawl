#include <types.h>
#pragma force_active on

struct fn27Entry {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct fn27Obj {
    u8 pad[0x18];
    s32 unk18;
};

extern "C" {
fn27Entry* fn_27_1BDD38(fn27Obj* obj, s32 idx) {
    s32 n = (obj->unk18 >> 26) + idx;
    if (n >= 0x14) {
        n -= 0x14;
    }
    return (fn27Entry*)((u8*)obj + 0x1c + n * 12);
}
}
