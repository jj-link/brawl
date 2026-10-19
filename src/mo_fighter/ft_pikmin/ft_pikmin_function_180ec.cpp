#pragma force_active on
struct Base {
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
    virtual void f13(unsigned long v);
};

extern "C" void fn_113_180EC(char* self) {
    Base* c = *(Base**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x64);
    c->f13(0x11000007);
}
