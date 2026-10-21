#include <types.h>
#pragma force_active on

extern "C" void fn_27_A756C();

struct Elem {
    char pad[0x1d];
    u8 flags;
};

struct Inner {
    virtual void f0();
    virtual Elem* get(int i);
    virtual void f4();
    virtual int count();
};

struct Outer {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(int v);
    char pad[0x30 - 0x04];
    Inner* m;
};

extern "C" void fn_27_A3E88(Outer* self) {
    self->f12(0);
    int n = self->m->count();
    for (int i = 0; i < n; i++) {
        if ((self->m->get(i)->flags >> 6) & 1) {
            self->m->get(i);
            fn_27_A756C();
        }
    }
}
