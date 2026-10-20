#include <types.h>
#pragma force_active on

struct Node {
    u32 m_a;
    u32 m_b;
    s32 m_c;
};

class Inner {
public:
    virtual void v0();
    virtual Node* v1();
};

class Outer {
public:
    u32 m_pad[4];
    Inner m_inner;
};

extern "C" s32 fn_27_319794(Outer* p) {
    return p->m_inner.v1()->m_c;
}
