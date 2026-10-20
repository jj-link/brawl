#include <types.h>
#pragma force_active on

class fnInner {
public:
    u32 m_a;
    u32 m_b;
};

class fnSub {
public:
    virtual void f0();
    virtual fnInner* f1();
};

class fnOuter {
public:
    u32 m_pad[4];
    fnSub m_sub;
};

extern "C" u32 fn_27_1C5D64(fnOuter* self) {
    return self->m_sub.f1()->m_b;
}
