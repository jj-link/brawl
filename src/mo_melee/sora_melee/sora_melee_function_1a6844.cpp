#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 unk0;
    u32 unk4;
    u32 field : 10;
    u32 rest : 22;
};

extern "C" {
void fn_27_1A6844(Fn27Bits* p, u32 v) {
    p->field = v;
}
}
