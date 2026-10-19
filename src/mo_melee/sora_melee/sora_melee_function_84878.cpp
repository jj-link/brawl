#pragma force_active on
struct Obj {
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
    virtual void f17();
    virtual void call(unsigned int, unsigned int, unsigned short*, int);
};

extern "C" void fn_27_84878(Obj* obj, unsigned int a, unsigned int b) {
    unsigned short local = 0;
    obj->call(a, b, &local, -1);
}
