#include <types.h>
#pragma force_active on

class fn27Target {
public:
    s32 m0;
    s32 m4;
    s32 m8;
};

class fn27Inner {
public:
    virtual void vf0();
    virtual fn27Target* vf1();
};

class fn27Outer {
public:
    u8 pad[0x10];
    fn27Inner m_inner;
};

extern "C" s32 fn_27_1AC0F0(fn27Outer* self) {
    return self->m_inner.vf1()->m8;
}
