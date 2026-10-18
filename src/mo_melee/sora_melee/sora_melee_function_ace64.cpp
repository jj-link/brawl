#include <types.h>
#pragma force_active on

class IFoo {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(u32* p);
};

class Obj {
public:
    u8 _0[0x34];
    IFoo m_foo;
    u8 _1[0x78 - 0x38];
    u32 m_flags;
};

struct Local {
    u32 flags;
    u32 b;
    u8 c;
};

extern "C" {
void fn_27_ACE64(Obj* self, u32 a, u32 b, u8 c) {
    Local s;
    s.flags = a & ~self->m_flags;
    s.b = b;
    s.c = c;
    if (self->m_foo.v6() == 0) {
        self->m_foo.v10();
    }
    self->m_foo.v12(&s.flags);
}
}
