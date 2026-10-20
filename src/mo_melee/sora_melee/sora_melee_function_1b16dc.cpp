#include <types.h>
#pragma force_active on

class fn27Iface {
public:
    virtual u32 vf0() = 0;
    virtual u32 vf1() = 0;
    virtual u32 vf2() = 0;
    virtual u32 vf3() = 0;
    virtual u32 vf4() = 0;
    virtual u32 vf5() = 0;
    virtual u32 vf6() = 0;
};

class fn27Wrapper {
public:
    u8 pad[8];
    fn27Iface* m_obj;
};

extern "C" {
u32 fn_27_1B16DC(fn27Wrapper* self) {
    return self->m_obj->vf4();
}
}
