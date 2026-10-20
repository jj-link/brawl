#include <types.h>
#pragma force_active on

struct fn_27_Inner {
    virtual void f0();
    virtual void f1();
};

struct fn_27_Outer {
    u8 pad[0x10];
    fn_27_Inner m_inner;
};

extern "C" void fn_27_F1360(fn_27_Outer* p) {
    fn_27_Inner* inner = &p->m_inner;
    inner->f1();
}
