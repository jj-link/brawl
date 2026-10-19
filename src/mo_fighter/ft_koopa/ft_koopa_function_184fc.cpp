#pragma force_active on
class IB {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual unsigned int f9(int arg);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int f13();
    virtual void f14();
    virtual void f15();
};

struct PModule {
    char pad0[0x3c];
    IB* a;
    char pad1[0x54 - 0x40];
    IB* b;
};

struct Arg {
    char pad[0xd8];
    PModule* p;
};

extern "C" {
int fn_102_184FC(void* unused, Arg* self) {
    if (self->p->b->f9(0) == 1) {
        return self->p->a->f13();
    }
    return 0;
}
}
