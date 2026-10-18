#include <types.h>
#pragma force_active on

class Iface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v10(s16 arg);
};

class Outer {
public:
    u32 m_0;
    u32 m_4;
    Iface* m_iface;
};

extern "C" {
void fn_27_DA824(Outer* self, s16 arg) {
    self->m_iface->v10(arg);
}
}
