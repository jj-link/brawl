#pragma force_active on
struct Inner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

struct Outer {
    char pad[4];
    Inner* inner;
};

extern "C" void fn_801C6090(Outer* p) {
    p->inner->vf2();
}
