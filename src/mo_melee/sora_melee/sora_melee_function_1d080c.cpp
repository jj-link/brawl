#include <types.h>
#pragma force_active on

struct Fn27Word {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1D080C(void* p, u32 v) {
    Fn27Word* w = (Fn27Word*)((u8*)p + 8);
    w->hi = v;
}
