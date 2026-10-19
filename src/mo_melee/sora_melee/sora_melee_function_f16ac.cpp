#include <types.h>
#pragma force_active on

class fn27Target {
public:
    u32 m_pad;
    u32 m_value;
};

class fn27Inner {
public:
    virtual void vfn0();
    virtual fn27Target* vfn1();
};

class fn27Outer {
public:
    u32 m_pad[4];
    fn27Inner m_inner;
};

extern "C" u32 fn_27_F16AC(fn27Outer* self) {
    return self->m_inner.vfn1()->m_value;
}
