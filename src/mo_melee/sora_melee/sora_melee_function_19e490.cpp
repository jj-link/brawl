#include <types.h>
#pragma force_active on

struct Bits {
    u32 a : 6;
    u32 f : 3;
    u32 b : 23;
};

struct Holder {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_19E490(Holder *h, u32 v) {
    h->bits.f = v;
}
