#include <types.h>
#pragma force_active on

struct fn_27_1A316C_Obj {
    u32 unk0;
    u32 unk4;
    u32 field : 6;
    u32 rest : 26;
};

extern "C" {
void fn_27_1A316C(fn_27_1A316C_Obj* p, u32 v) {
    p->field = v;
}
}
