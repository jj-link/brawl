#include <types.h>
#pragma force_active on

struct S {
    u32 unk0;
    u32 unk4;
    u32 pad : 8;
    u32 field : 4;
    u32 rest : 20;
};

extern "C" void fn_27_295A1C(S* p, u32 v) {
    p->field = v;
}
