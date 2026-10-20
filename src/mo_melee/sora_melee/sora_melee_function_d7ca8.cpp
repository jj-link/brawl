#pragma force_active on
struct Sub {
    virtual ~Sub();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

struct Outer {
    char pad[0xc];
    Sub sub;
};

extern "C" void fn_27_D7CA8(Outer* self) {
    self->sub.v3();
}
