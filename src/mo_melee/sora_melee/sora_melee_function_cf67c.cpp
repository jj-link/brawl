#include <types.h>
#pragma force_active on

extern "C" {
struct Bits {
    u32 pad[2];
    u32 hi : 6;
    u32 lo : 26;
};

void fn_27_CF67C(Bits* p, u32 v) {
    p->hi = v;
}
}
