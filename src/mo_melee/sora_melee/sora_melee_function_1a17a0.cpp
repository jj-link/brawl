#include <types.h>
#pragma force_active on

struct fn_27_1A17A0_obj {
    u32 unk0;
    u32 unk4;
    u32 field : 6;
    u32 rest : 26;
};

extern "C" {
void fn_27_1A17A0(fn_27_1A17A0_obj* p, u32 v) {
    p->field = v;
}
}
