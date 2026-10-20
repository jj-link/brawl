#include <types.h>
#pragma force_active on

struct fn_27_Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3();
    virtual void f4();
    virtual void f5();
};

struct fn_27_Outer {
    u8 pad[0x90];
    fn_27_Inner* inner;
};

extern "C" s32 fn_27_17674(fn_27_Outer* p) {
    return p->inner->f3();
}
