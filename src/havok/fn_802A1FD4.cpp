#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void* ptr, u16 size, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct Foo {
    u32 m_00;
    u16 m_04;
    u16 m_06;
};

extern "C" void __dl__14Class_802A1FD4FPv(Foo* self) {
    lbl_805A0EB8->free(self, self->m_04, 0x1d);
}
