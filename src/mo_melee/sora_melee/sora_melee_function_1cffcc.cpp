#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" u32 fn_27_1CFFCC(const X* p) {
    struct Bits {
        u32 x : 12;
        u32 y : 1;
        u32 z : 19;
    };
    const Bits* b = (const Bits*)&p->c;
    return b->y;
}