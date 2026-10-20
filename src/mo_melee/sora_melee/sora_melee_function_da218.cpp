#include <types.h>
#pragma force_active on

struct fnInner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct fnOuter {
    u8 pad[8];
    fnInner* m_inner;
};

extern "C" {
void fn_27_DA218(fnOuter* p) {
    p->m_inner->f4();
}
}
