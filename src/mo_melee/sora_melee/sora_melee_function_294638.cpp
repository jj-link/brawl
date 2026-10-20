#pragma force_active on
struct Sub {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
};

struct Holder {
    char pad[0x10];
    Sub sub;
};

extern "C" void fn_27_294638(Holder* p) {
    p->sub.s3();
}
