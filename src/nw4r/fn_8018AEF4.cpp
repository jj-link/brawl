#include <types.h>
#pragma force_active on

struct S {
    s32 f0, f4;
    u16 f8, fA;
    f32 fC, f10;
    u16 f14, f16;
    union {
        u32 flags;
        struct {
            u32 pad : 5;
            u32 a : 2;
            u32 b : 2;
            u32 rest : 23;
        };
    };
};

extern "C" void fn_8018AEF4(S* d, S s) {
    u32 a = d->a;
    u32 b = d->b;
    *d = s;
    d->a = a;
    d->b = b;
}
