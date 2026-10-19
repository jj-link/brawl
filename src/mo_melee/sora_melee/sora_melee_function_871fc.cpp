#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
};

struct soOuter {
    u8 pad[0x14];
    soInner* m_inner;
};

extern "C" {
u32 fn_27_871FC(soOuter* self) {
    return *(u32*)self->m_inner->vf1();
}
}
