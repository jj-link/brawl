#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void vf0() = 0;
    virtual Sub* vf3(u32 arg) = 0;

    u32 m_unk4;
    u32 m_unk8;
    u32 m_unkC;
    u8 m_b7 : 1;
    u8 m_flag : 1;
    u8 m_rest : 6;
};

class Obj {
public:
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual u32 vf16(u32 arg) = 0;

    u8 m_pad4[0x34];
    Sub* m_sub;
};

extern "C" {
void fn_27_BB040(Obj* self, u32 flag, u32 arg) {
    if (self->vf16(arg) == 1) {
        Sub* s = self->m_sub->vf3(arg);
        s->m_flag = flag;
    }
}
}
