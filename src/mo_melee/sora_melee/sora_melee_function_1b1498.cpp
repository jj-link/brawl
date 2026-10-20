#pragma force_active on
class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class Outer {
public:
    unsigned char pad[0x10];
    Sub sub;
};

extern "C" void fn_27_1B1498(Outer* p) {
    p->sub.f3();
}
