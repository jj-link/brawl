#pragma force_active on
typedef unsigned int u32;

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u32 pad[4];
    Inner inner;
};

extern "C" void fn_27_293BF0(Outer* p) {
    Inner* ip = &p->inner;
    ip->f1();
}
