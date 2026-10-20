#pragma force_active on
struct SoSub {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct SoOuter {
    char pad[0xc];
    SoSub sub;
};

extern "C" void fn_27_1AA014(SoOuter* p) {
    p->sub.vf4();
}
