#pragma force_active on
typedef unsigned short u16;

struct Target {
    virtual ~Target();
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
    virtual void call(int, int, u16*, int);
};

extern "C" void fn_27_8482C(Target* self, int a, int b) {
    u16 out = 0;
    self->call(a, b, &out, -1);
}
