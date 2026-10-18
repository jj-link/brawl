#include <types.h>
#pragma force_active on

class soVirtualTarget {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf10(s16 value);
};

class soVirtualHolder {
public:
    char pad[0x8];
    soVirtualTarget* m_target;
};

extern "C" void fn_27_C518C(soVirtualHolder* self, s16 value) {
    self->m_target->vf10(value);
}
