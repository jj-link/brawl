#include <types.h>
#pragma force_active on

struct soInner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct soOuter {
    u8 pad[0x18];
    soInner* m_inner;
};

extern "C" {
void fn_27_B4674(soOuter* p) {
    p->m_inner->f3();
}
}
