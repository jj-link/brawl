#include <types.h>
#pragma force_active on

struct X {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void target();
};

struct BigClass {
    unsigned char pad[0x12a0];
    X m_member;
};

extern "C" void fn_27_3AEE94(BigClass* self) {
    self->m_member.target();
}
