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
};

struct soOuter {
    u32 unk0;
    u32 unk4;
    soInner* m_inner;
};

extern "C" void fn_27_1B177C(soOuter* p) {
    p->m_inner->f4();
}
