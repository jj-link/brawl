#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual s32 vf3();
    virtual void vf4();
    virtual s32 vf5();
};

class soOuter {
public:
    u8 pad[0x48];
    soInner* m_48;
};

extern "C" s32 fn_27_4AB88(soOuter* self) {
    return self->m_48->vf3();
}
