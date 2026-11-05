#include <types.h>
#pragma force_active on

extern "C" void fn_27_37A14(void* p, u32 index);

struct Elem {
    unsigned char pad[0x64];
    u8 m_flag;
};

class ArrB {
public:
    virtual void v0();
    virtual Elem* get(int index);
    virtual void v2();
    virtual int size();
};

class A {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int value);
};

class Mod {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();

    unsigned char pad0[0x28];
    A* m2C;
    unsigned char pad1[0x34 - 0x30];
    ArrB* m34;
    unsigned char pad2[0x48 - 0x38];
    float f48;
    float f4C;
    float f50;
    unsigned char pad3[0x64 - 0x54];
    ArrB* m64;
    unsigned char m68[0x94 - 0x68];
    int m94;
    int m98;
    u32 : 1;
    u32 m9C_bit : 1;
    u32 m9C_rest : 30;
};

struct Params {
    unsigned char pad[0xC];
    u32 flags;
};

extern "C" void fn_27_40784(Mod* self, int a1, int a2, Params* p) {
    self->m2C->v5(-1);
    u32 flags = p->flags;
    self->m98 = -1;
    self->f48 = 1.0f;
    self->f4C = 0.0f;
    self->f50 = 0.0f;
    self->m94 = 0;
    self->m9C_bit = 0;
    if (!((flags >> 11) & 1)) {
        self->v4();
    }
    if ((p->flags >> 10) & 1) {
        return;
    }
    u8 zero = 0;
    int i;
    for (i = 0; i < self->m34->size(); i++) {
        self->m34->get(i)->m_flag = zero;
    }
    int n = self->m64->size();
    for (i = 0; i < n; i++) {
        fn_27_37A14(&self->m68, i);
    }
}
