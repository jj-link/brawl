#pragma force_active on
extern "C" void fn_27_1947AC(void* a, void* b);

class IFace {
public:
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
    virtual void* f18();
};

struct Holder {
    char pad[0x70];
    IFace* p;
};

struct Actor {
    char pad[0xd8];
    Holder* h;
};

extern "C" {
void fn_27_151AE0(void* unused, Actor* actor) {
    void* r = actor->h->p->f18();
    fn_27_1947AC(actor, r);
}
}
