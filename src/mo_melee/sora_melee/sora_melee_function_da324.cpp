#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(s16 x);
};

class fnOuter {
public:
    u32 m_00;
    u32 m_04;
    fnInner* m_08;
};

extern "C" {
void fn_27_DA324(fnOuter* p, s16 x) {
    p->m_08->v8(x);
}
}
