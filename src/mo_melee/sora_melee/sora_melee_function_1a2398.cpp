#include <types.h>
#pragma force_active on

struct Foo {
    u32 a;
    u32 b;
    struct {
        unsigned f0 : 4;
        int f1 : 4;
        unsigned f2 : 24;
    } c;
};

extern "C" s32 fn_27_1A2398(const Foo* p) {
    return p->c.f1;
}
