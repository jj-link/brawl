#pragma force_active on
class Dispatch {
public:
    unsigned int data0;
    unsigned int data1;

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct Object {
    unsigned char padding0[0x0C];
    Dispatch dispatch;
    unsigned char padding1[0x10];
    unsigned int value;
};

extern "C" void fn_27_281A90(Object* self, unsigned int value) {
    self->value = value;
    self->dispatch.f6();
}
