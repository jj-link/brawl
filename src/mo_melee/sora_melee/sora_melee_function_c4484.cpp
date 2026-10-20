#include <types.h>
#pragma force_active on

struct Foo {
    u32 m0;
    u32 m4;
    u32 m8;
};

extern "C" s32 fn_27_C4484(Foo *f) {
    return (s32)f->m8 >> 26;
}
