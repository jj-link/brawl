#include <types.h>
#pragma force_active on

class fn27Ret {
public:
    u32 m_a;
    u32 m_value;
};

class fn27Sub {
public:
    virtual void v0();
    virtual fn27Ret* v1();
    virtual void v2();
    virtual void v3();
};

class fn27Outer {
public:
    u8 m_pad[0x10];
    fn27Sub m_sub;
};

extern "C" u32 fn_27_EF900(fn27Outer* self) {
    return self->m_sub.v1()->m_value;
}
