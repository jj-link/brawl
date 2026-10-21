#pragma force_active on
class Base {
public:
    unsigned int padding[2];

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class Object : public Base {
public:
    unsigned char flag : 1;
    unsigned char rest : 7;
};

extern "C" void fn_27_A793C(Object* self) {
    self->flag = 0;
    self->f6();
}
