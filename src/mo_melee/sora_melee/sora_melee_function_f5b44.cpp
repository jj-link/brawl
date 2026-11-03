#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void* vf1(s32 idx);
    virtual void vf2();
    virtual s32 vf3();
};

class soVisitor {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(void** p);
};

struct soOuter {
    u8 m_pad[0x10];
    soInner m_inner;
};

extern "C" void fn_27_F5B44(soOuter* self, soVisitor* visitor) {
    s32 count = self->m_inner.vf3();
    for (s32 i = 0; i < count; i++) {
        void* p = self->m_inner.vf1(i);
        visitor->vf10(&p);
    }
}
