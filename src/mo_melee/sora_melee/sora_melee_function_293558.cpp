#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void f0();
    virtual Sub* f3();
    s32 m_value;
};

class Outer {
public:
    u8 m_pad[0x10];
    Sub m_sub;
};

extern "C" {
s32 fn_27_293558(Outer* self) {
    return self->m_sub.f3()->m_value;
}
}
