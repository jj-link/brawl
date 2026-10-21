#pragma force_active on
struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void target();
};

struct Container {
    char _pad[0x10];
    Base* p;
};

extern "C" void fn_80184178(Container* c) {
    if (c->p == 0) {
        return;
    }
    c->p->target();
}
