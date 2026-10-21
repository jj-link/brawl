#pragma force_active on
extern int lbl_805A0334;

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
    virtual void call(unsigned int, int);

    char padding[0xE4 - 4];
    unsigned int value;
};

extern "C" void fn_80108E44(Object* self) {
    self->call(self->value, lbl_805A0334);
}
