#include <types.h>
#pragma force_active on

struct Foo {
    u32 m0;
    u32 m4;
    u32 m8;
};

extern "C" {
bool fn_27_C9E18(const Foo* f);
}

extern "C" bool fn_27_C9E18(const Foo* f) {
    return (f->m8 >> 25) & 1;
}
