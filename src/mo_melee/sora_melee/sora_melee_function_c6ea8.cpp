#include <types.h>
#pragma force_active on

class fn27Inner {
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
    virtual void call(u32& value);
};

class fn27Outer {
public:
    u8 pad[0x50];
    fn27Inner m_inner;
};

extern "C" {
void fn_27_C6EA8(fn27Outer* self, u32 value) {
    self->m_inner.call(value);
}
}
