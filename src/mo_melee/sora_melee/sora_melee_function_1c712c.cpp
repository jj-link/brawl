#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0();
    virtual s32* vf1();
    virtual void vf2();
    virtual void vf3();
};

class fn27Outer {
public:
    u8 pad[0x10];
    fn27Inner m_inner;
};

extern "C" {
s32 fn_27_1C712C(fn27Outer* p) {
    return p->m_inner.vf1()[1];
}
}
