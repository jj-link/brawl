#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 hi : 4;
    u32 f : 4;
    u32 lo : 24;
};

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    Fn27Bits unk8;
};

extern "C" {
void fn_27_38D9C(Fn27Obj* p, u32 v) {
    p->unk8.f = v;
}
}
