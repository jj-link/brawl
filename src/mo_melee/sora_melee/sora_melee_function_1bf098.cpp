#include <types.h>
#pragma force_active on

struct fnSub {
    virtual void f0();
    virtual fnSub* f1();
    s32 m_4;
};

struct fnOuter {
    s32 m_0;
    s32 m_4;
    s32 m_8;
    s32 m_c;
    fnSub m_10;
};

extern "C" {
s32 fn_27_1BF098(fnOuter* p) {
    return p->m_10.f1()->m_4;
}
}
