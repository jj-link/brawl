#include <types.h>
#pragma force_active on

class FieldObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(u32 a, u32 b);
};

class Owner {
public:
    u8 pad[0x2aac];
    FieldObj m_obj;
};

extern "C" void fn_27_28FDEC(Owner* self, u32 a) {
    self->m_obj.f5(a, 0x1000000e);
}
