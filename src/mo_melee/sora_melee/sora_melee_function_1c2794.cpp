#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual s32 f8();
};

class soOuter {
public:
    u8 pad[0x10];
    soInner m_inner;
};

extern "C" s32 fn_27_1C2794(soOuter* p) {
    return p->m_inner.f8();
}
