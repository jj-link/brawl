#include <types.h>
#pragma force_active on

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1A7640(fn27Obj* p) {
    return (s32)(((p->unk8 >> 23) & 0x1F) << 27) >> 28;
}
}
