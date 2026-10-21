#pragma force_active on

struct Object {
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
    virtual void f11(unsigned int, unsigned int);

    char padding[0xE0];
    unsigned int value;
};

extern unsigned int lbl_805A030C;

extern "C" void fn_800FD630(Object* self) {
    self->f11(self->value, lbl_805A030C);
}
