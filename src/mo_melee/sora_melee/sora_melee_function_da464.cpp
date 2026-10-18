#include <types.h>
#pragma force_active on

class fn_27_DA464_Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(s16 arg);
};

class fn_27_DA464_Outer {
public:
    u8 pad[8];
    fn_27_DA464_Inner* m_inner;
};

extern "C" {
void fn_27_DA464(fn_27_DA464_Outer* outer, s16 arg) {
    outer->m_inner->vf8(arg);
}
}
