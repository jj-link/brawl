#include <types.h>
#pragma force_active on

struct FE220Bits {
    u32 pad[2];
    u32 hi : 6;
    u32 rest : 26;
};

extern "C" void fn_27_FE220(FE220Bits* p, u32 v) {
    p->hi = v;
}
