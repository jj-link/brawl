#pragma force_active on
struct Inner {
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
    virtual void f11(void* a, void* b);
    char pad[0xE4 - 4];
    void* f_e4;
};

struct Sub {
    char pad[0x10];
    void* val;
};

extern "C" void fn_800FD44C(Sub** a, Inner* b) {
    b->f11(b->f_e4, (*a)->val);
}
