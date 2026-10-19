#include <types.h>
#pragma force_active on

class Target {
public:
    s32 m_pad;
    s32 m_value;
};

class Inner {
public:
    virtual void vf0();
    virtual Target* getTarget();
};

class Outer {
public:
    u8 m_pad[0x10];
    Inner m_inner;
};

extern "C" {
    s32 fn_27_F3458(Outer* self) {
        return self->m_inner.getTarget()->m_value;
    }
}
