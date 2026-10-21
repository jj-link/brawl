#pragma force_active on
class Target {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void call(short);
};

struct Wrapper {
    char padding[8];
    Target* target;
};

extern "C" void fn_27_1B16A8(Wrapper* self, int value) {
    self->target->call((short)value);
}
