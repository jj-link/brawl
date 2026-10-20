#include <types.h>
#pragma force_active on

class fnZ {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setArg(u32 arg);
    virtual u32 getResult();
};

class fnC {
public:
    char pad[0x54];
    fnZ* m_z;
};

class fnB {
public:
    char pad[0xd8];
    fnC* m_c;
};

class fnA {
public:
    char pad[0x60];
    fnB* m_b;
};

extern "C" void fn_27_1DA618(fnA* self, u32 arg) {
    if (self->m_b->m_c->m_z->getResult() == 1) {
        self->m_b->m_c->m_z->setArg(arg);
    }
}
