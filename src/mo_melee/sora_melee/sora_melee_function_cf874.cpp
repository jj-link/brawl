#include <types.h>
#pragma force_active on

struct Foo {
    u32 _0;
    u32 _4;
    u32 a : 18;
    u32 b : 1;
};

extern "C" u32 fn_27_CF874(Foo* p) {
    return p->b;
}
