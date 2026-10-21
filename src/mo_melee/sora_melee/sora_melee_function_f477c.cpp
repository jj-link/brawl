#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual s32 getValue(u32 idx);
    virtual void v2();
    virtual s32 getCount();
    virtual void v4();
    virtual void v5();
};

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void set(s32& value);
    virtual void v11();
    virtual void v12();
};

class Outer {
public:
    u32 m_pad[4];
    Inner m_inner;
};

extern "C" {
void fn_27_F477C(Outer* self, Target* target) {
    s32 count = self->m_inner.getCount();
    for (s32 i = 0; i < count; i++) {
        s32 value = self->m_inner.getValue(i);
        target->set(value);
    }
}
}
