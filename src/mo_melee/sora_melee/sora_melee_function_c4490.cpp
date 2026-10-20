#include <types.h>
#pragma force_active on

struct Fn27Bits {
    u32 unk0;
    u32 unk4;
    u32 hi : 6;
    u32 rest : 26;
};

extern "C" void fn_27_C4490(Fn27Bits* p, u32 v) {
    p->hi = v;
}
