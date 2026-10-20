#include <types.h>
#pragma force_active on

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 field : 5;
    u32 rest : 27;
};

extern "C" {
void fn_27_10EBB8(Fn27Obj* p, u32 v) {
    p->field = v;
}
}
