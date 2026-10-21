#include <types.h>
#pragma force_active on

struct CBase {
    char pad[8];
};

class A;

struct C : CBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void call(int, A*);
};

struct B {
    char pad[0x9c];
    C* c;
};

class A {
public:
    char pad[0xd8];
    B* b;
};

struct SelfBase {
    char pad[0x3c];
};

class Self : public SelfBase {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void on(int);

    char pad2[0x60 - 0x40];
    A* m_a;
    char pad3[0x169a - 0x64];
    unsigned char m_flag;
};

extern "C" void fn_27_1D8FC8(void*, int);

extern "C" void fn_27_1E1DFC(Self* self, int arg) {
    A* a = self->m_a;
    C* c = a->b->c;
    c->call(arg, a);
    fn_27_1D8FC8(self, arg);
    if (self->m_flag == 1 && self != 0) {
        self->on(1);
    }
}
