#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(void* arg);
};

class Owner {
public:
    int m_pad;
    Object_vptr_0* m_child;
};

extern "C" {

void fn_8027A1A0(Owner* self, Object_vptr_0* child) {
    self->m_child = child;
    if (child != 0)
        child->slot1(self);
}

}
