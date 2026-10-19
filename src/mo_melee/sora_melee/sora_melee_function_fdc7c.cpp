#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0();
    virtual u32* vf1();
};

class fn27Owner {
public:
    u8 m_pad[0x10];
    fn27Inner m_inner;
};

extern "C" {
u32 fn_27_FDC7C(fn27Owner* self) {
    return self->m_inner.vf1()[1];
}
}
