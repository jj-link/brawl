#pragma force_active on
struct Inner {
    char pad[0x10];
    void* f10;
};

struct IFace {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void call(void* p) = 0;
};

struct Obj {
    IFace* f0;
    Inner* f4;
    char pad8[0x1C - 0x8];
    unsigned char f1C;
};

extern "C" void fn_800FBF90(Obj* r3) {
    r3->f0->call(r3->f4->f10);
    r3->f1C = 0;
}
