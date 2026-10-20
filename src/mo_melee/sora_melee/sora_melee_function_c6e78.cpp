#include <types.h>
#pragma force_active on

class soGeneralInner {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual s32* vfunc2();
};

class soGeneralOuter {
public:
    u8 m_pad[0x50];
    soGeneralInner m_inner;
};

extern "C" {
    s32 fn_27_C6E78(soGeneralOuter* self) {
        return *self->m_inner.vfunc2();
    }
}
