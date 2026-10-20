#include <types.h>
#pragma force_active on

class fnSub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class fnOuter {
public:
    u32 pad[4];
    fnSub m_sub;
};

extern "C" void fn_27_C4AC8(fnOuter* p) {
    fnSub* s = &p->m_sub;
    s->f1();
}
