#include <types.h>
#pragma force_active on

namespace {
    struct Foo {
        u32 m0x0;
        u32 m0x4;
        u32 m0x8a : 6;
        u32 m0x8 : 6;
        u32 m0x8pad : 4;
    };
}

extern "C" void fn_27_1CFB3C(Foo* self, int v) {
    self->m0x8 = v;
}
