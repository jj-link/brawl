#include <types.h>
#pragma force_active on

struct Data {
    u32 a;
    u32 b;
    s16 c;
    s16 d;
};

struct Foo {
    virtual void f0();
    virtual void f1();
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual Data* f26(void*);
};

extern "C" void fn_27_1026A8(Foo* self, void* a2, void* a3) {
    Data* p = self->f26(a2);
    Data* q = self->f26(a3);
    q->a = p->a;
    q->b = p->b;
    q->c = p->c;
    q->d = p->d;
}
