#include <types.h>
#pragma force_active on

struct Foo {
    u32 a;
    u32 b;
    s32 c;
};

extern "C" s32 fn_27_29615C(Foo* p) {
    return p->c >> 26;
}
