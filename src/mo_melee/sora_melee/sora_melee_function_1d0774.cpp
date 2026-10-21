#include <types.h>
#pragma force_active on

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 pad : 4;
    u32 field : 4;
    u32 rest : 24;
};

extern "C" void fn_27_1D0774(Obj* p, u32 val) {
    p->field = val;
}
