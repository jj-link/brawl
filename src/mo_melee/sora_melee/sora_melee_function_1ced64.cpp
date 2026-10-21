#pragma force_active on
class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void invoke();
};

struct Object {
    char padding[0x10];
    Interface member;
};

extern "C" void fn_27_1CED64(Object* self) {
    self->member.invoke();
}
