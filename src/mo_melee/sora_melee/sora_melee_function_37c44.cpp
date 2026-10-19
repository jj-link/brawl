#include <types.h>
#pragma force_active on

extern "C" void fn_27_3816C();

class fn27Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class fn27Outer {
public:
    u8 pad[8];
    fn27Inner* m_inner;
};

extern "C" {
void fn_27_37C44(fn27Outer* p) {
    p->m_inner->vf1();
    fn_27_3816C();
}
}
