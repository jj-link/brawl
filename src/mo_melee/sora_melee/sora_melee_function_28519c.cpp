#pragma force_active on
class Inner {
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
};

class Outer {
public:
    char pad[0x3d10];
    Inner inner;
};

extern "C" void fn_27_28519C(Outer* p) {
    Inner* ip = &p->inner;
    ip->f8();
}
