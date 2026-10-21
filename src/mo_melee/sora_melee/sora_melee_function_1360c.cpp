#pragma force_active on
struct Base {
    char padding[8];
};

class Object : public Base {
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void call(unsigned int);

    char padding[0x34];
    unsigned int value;
};

extern "C" void fn_27_1360C(Object* self) {
    self->call(self->value);
}
