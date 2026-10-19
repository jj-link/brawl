#include <types.h>
#pragma force_active on

class SubObj {
public:
    virtual void f0();
    virtual SubObj* f1();
    u32 m_pad;
    void* m_ptr;
};

class Outer {
public:
    u32 m_pad[4];
    SubObj m_sub;
};

extern "C" void* fn_27_D87B8(Outer* self) {
    return self->m_sub.f1()->m_ptr;
}
