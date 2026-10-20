#pragma force_active on
class Y {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};

struct X {
    char pad[0xC];
    Y* y;
};

struct Outer {
    char pad[0x180];
    X* x;
};

extern "C" void fn_27_263954(Outer* p) {
    p->x->y->f7();
}
