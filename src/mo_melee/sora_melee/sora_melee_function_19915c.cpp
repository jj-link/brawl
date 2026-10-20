#include <types.h>
#pragma force_active on

struct fn27Bits {
    u32 unk0;
    u32 unk4;
    u32 flags : 3;
    u32 rest : 29;
};

extern "C" void fn_27_19915C(fn27Bits* p, u32 v) {
    p->flags = v;
}
