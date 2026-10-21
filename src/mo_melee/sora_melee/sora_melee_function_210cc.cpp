#pragma force_active on
class Object {
public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void target();
};

extern "C" void fn_27_210CC(Object* self) {
    self->target();
}
