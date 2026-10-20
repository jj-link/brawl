#include <types.h>
#pragma force_active on

struct Inner {
    virtual u32 f0();
    virtual u32 f1();
    virtual u32 f2();
    virtual u32 f3();
    virtual u32 f4();
    virtual u32 f5();
    virtual u32 f6();
};

struct Mid {
    u8 pad[0x1c];
    Inner* inner;
};

struct Outer {
    u8 pad[0x180];
    Mid* mid;
};

extern "C" u32 fn_27_263738(Outer* self) {
    return self->mid->inner->f4();
}
