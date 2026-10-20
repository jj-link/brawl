#include <types.h>
#pragma force_active on

class fn_27_1ACB14_Ret {
public:
    u32 m_pad[2];
    u32 m_val;
};

class fn_27_1ACB14_Sub {
public:
    virtual void fn0();
    virtual fn_27_1ACB14_Ret* fn1();
};

class fn_27_1ACB14_Outer {
public:
    u32 m_pad[4];
    fn_27_1ACB14_Sub m_sub;
};

extern "C" {
u32 fn_27_1ACB14(fn_27_1ACB14_Outer* self) {
    return self->m_sub.fn1()->m_val;
}
}
