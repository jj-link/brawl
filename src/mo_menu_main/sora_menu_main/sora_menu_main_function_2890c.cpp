#pragma force_active on
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

struct Obj40 {
    char pad[0x40];
    void* f40;
};

struct Obj264 {
    char pad[0x264];
    void* f264;
};

struct Menu {
    char pad0[0x64C];
    Obj264* f64C;
    Obj40* f650;
    IFace* f654;
    char pad1[0x674 - 0x658];
    void* f674;
    char pad2[0x680 - 0x678];
    void* f680;
};

extern "C" {
void fn_800B8EDC(void*, void*);
void free__13gfHeapManagerFPv(void*);
}

extern "C" void fn_2_2890C(Menu* r3) {
    r3->f654->call(r3->f650->f40);
    fn_800B8EDC(r3->f674, r3->f64C->f264);
    free__13gfHeapManagerFPv(r3->f680);
}
