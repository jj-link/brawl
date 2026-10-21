#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(void* p, u16 size, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct MyObj {
    s32 m_00;
    u16 m_04;
    u16 m_06;
};

extern "C" void dtor_80302A88(MyObj* self) {
    lbl_805A0EB8->vf5(self, self->m_04, 0x25);
}
