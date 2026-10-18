#pragma force_active on
struct V {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void f(int, bool);
};

struct Inner {
    char pad[0x3c];
    V* obj;
};

struct Outer {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_109_CC1C(int a, Outer* arg) {
    arg->inner->obj->f(0, false);
}