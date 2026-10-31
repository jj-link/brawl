#include <types.h>
#pragma force_active on

class soFlagOwner {
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
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void onBitCleared();
    u8 m_pad[0x534];
    u32 m_flags;
};

extern "C" void fn_27_14CAB0(soFlagOwner* self, u32 bit) {
    u32 mask = 1u << bit;
    if (!(self->m_flags & mask)) {
        return;
    }
    self->m_flags &= ~mask;
    self->onBitCleared();
}
