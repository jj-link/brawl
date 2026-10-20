#include <types.h>
#pragma force_active on

struct Flags {
    u32 pad0[2];
    u32 hi : 6;
    u32 rest : 26;
};

extern "C" void fn_27_FECF8(Flags* p, u32 v) {
    p->hi = v;
}
