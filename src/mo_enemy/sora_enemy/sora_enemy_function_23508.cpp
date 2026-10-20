#include <types.h>
#pragma force_active on

class fn41Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vfA(void* p);
};

class fn41Obj : public fn41Base {
public:
    void* m_pad[(0x54 - 4) / 4];
    void* m_member;
};

extern "C" void fn_41_23508(fn41Obj* self) {
    self->vfA(&self->m_member);
}
