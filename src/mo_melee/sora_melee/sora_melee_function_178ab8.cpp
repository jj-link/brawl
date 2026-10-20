#include <types.h>
#pragma force_active on

struct fn27Inner {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(s32 v);
};

struct fn27Mid {
    u8 pad[0x3c];
    fn27Inner* inner;
};

struct fn27Outer {
    u8 pad[0xd8];
    fn27Mid* mid;
};

extern "C" {
void fn_27_178AB8(s32 unused, fn27Outer* p) {
    p->mid->inner->f7(-1);
}
}
