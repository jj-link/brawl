#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1A5878(Fn27Obj* p) {
    u32 v = p->unk8;
    v = ((v << 8) | (v >> 24)) & 0xF8000000;
    return (s32)v >> 28;
}
