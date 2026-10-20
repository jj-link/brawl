#include <types.h>
#pragma force_active on

struct Sub {
    virtual s32 f0();
    virtual s32 f1();
    virtual s32 f2();
    virtual s32 f3();
    virtual s32 f4();
    virtual s32 f5();
};

struct Outer {
    u32 pad[4];
    Sub sub;
};

extern "C" s32 fn_27_1AD1F4(Outer* self) {
    return self->sub.f3();
}
