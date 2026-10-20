#include <types.h>
#pragma force_active on

class fn_27_Pad {
public:
    u32 m_pad0;
    u32 m_pad4;
};

class fn_27_Obj : public fn_27_Pad {
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
    u8 pad[0x5C - 12];
    s32 m_int5C;
    f32 m_float60;
};

extern const float lbl_27_rodata_26F0;

extern "C" {
void fn_27_1966FC(fn_27_Obj* self) {
    self->vf11();
    self->m_int5C = 0;
    self->m_float60 = lbl_27_rodata_26F0;
}
}
