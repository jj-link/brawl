#include <types.h>
#pragma force_active on

class SubObj {
public:
    u8 m_pad[0x18];
    float m_value;
};

class Obj {
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
    virtual void vf22();
    virtual void vf23();
    virtual SubObj* vf24();
};

extern "C" {
void fn_801BD424(Obj* self, float value) {
    SubObj* sub = self->vf24();
    sub->m_value = value;
}
}
