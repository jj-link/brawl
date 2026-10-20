#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class fnOuter {
public:
    u32 pad[3];
    fnInner m_inner;
};

extern "C" void fn_27_292438(fnOuter* p) {
    fnInner* q = &p->m_inner;
    q->f4();
}
