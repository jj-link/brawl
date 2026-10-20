#pragma force_active on
struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    char pad[0x10];
    Sub sub;
};

extern "C" void fn_27_1C0114(Outer* p) {
    Sub* s = &p->sub;
    s->f1();
}
