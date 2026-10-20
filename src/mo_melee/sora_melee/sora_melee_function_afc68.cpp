#pragma force_active on
struct fn27Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct fn27Outer {
    char pad[0x10];
    fn27Sub sub;
};

extern "C" {
void fn_27_AFC68(fn27Outer* p) {
    p->sub.v3();
}
}
