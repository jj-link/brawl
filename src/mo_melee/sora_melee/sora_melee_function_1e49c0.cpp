#pragma force_active on
struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
};

struct Outer {
    int pad[3];
    Sub sub;
};

extern "C" int fn_27_1E49C0(Outer* self) {
    return self->sub.v4();
}
