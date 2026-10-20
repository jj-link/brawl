#include <types.h>
#pragma force_active on

struct Foo {
    u32 pad[2];
    u32 f : 6;
    u32 f2 : 3;
    u32 f3 : 23;
};

extern "C" void fn_27_19FC1C(Foo* foo, u32 v) {
    foo->f2 = v;
}
