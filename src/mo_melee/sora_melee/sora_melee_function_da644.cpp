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
    virtual void vf8(s16 value);
};

class soVirtualOwner {
public:
    u8 pad[8];
    soVirtualTarget* m_target;
};

extern "C" {
void fn_27_DA644(soVirtualOwner* owner, s16 value) {
    owner->m_target->vf8(value);
}
}
