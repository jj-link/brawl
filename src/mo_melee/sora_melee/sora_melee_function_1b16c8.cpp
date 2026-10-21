#pragma force_active on
class Target {
public:
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void invoke();
};

struct Wrapper {
    unsigned char padding[8];
    Target* target;
};

extern "C" void fn_27_1B16C8(Wrapper* self) {
    self->target->invoke();
}
