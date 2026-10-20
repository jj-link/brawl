#pragma force_active on
struct fn_27_Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct fn_27_Outer {
    unsigned char pad[0x10];
    fn_27_Sub sub;
};

extern "C" {
void fn_27_1B14B8(fn_27_Outer* p) {
    p->sub.f3();
}
}
