#include <types.h>
#pragma force_active on

class fnTarget {
public:
    u32 m_pad;
    void* m_ptr;
};

class fnInner {
public:
    virtual void f0();
    virtual fnTarget* f1();
    virtual void f2();
    virtual void f3();
};

class fnOuter {
public:
    u32 m_pad[4];
    fnInner m_inner;
};

extern "C" {
void* fn_27_D8DB4(fnOuter* p) {
    fnInner* inner = &p->m_inner;
    return inner->f1()->m_ptr;
}
}
