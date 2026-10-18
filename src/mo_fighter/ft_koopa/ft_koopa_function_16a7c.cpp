#pragma force_active on
extern "C" {
void fn_102_169B4(void* arg);
}

// Module dispatched through the vtable at +0x50/0x54/0x60.
struct SndModule {
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
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void fn50(int) = 0;  // 0x50
    virtual void fn54(int) = 0;  // 0x54
    virtual void v18() = 0;      // 0x58
    virtual void v19() = 0;      // 0x5C
    virtual void fn60(int) = 0;  // 0x60
};

// Module with getKind at 0x14 and setKind at 0x20.
struct SitModule {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual int getKind() = 0;          // 0x14
    virtual void s4() = 0;              // 0x18
    virtual void s5() = 0;              // 0x1C
    virtual void setKind(int, int) = 0; // 0x20
};

// Module whose vtable pointer sits at +8.
struct GroundData {
    int a;
    int b;
};

struct GroundModule : GroundData {
    virtual void w0() = 0;
    virtual void w1() = 0;
    virtual void w2() = 0;
    virtual void w3() = 0;
    virtual void w4() = 0;
    virtual void w5() = 0;
    virtual void w6() = 0;
    virtual void w7() = 0;
    virtual void w8() = 0;
    virtual void w9() = 0;
    virtual void w10() = 0;
    virtual void w11() = 0;
    virtual void w12() = 0;
    virtual void w13() = 0;
    virtual void w14() = 0;
    virtual void w15() = 0;
    virtual void w16() = 0;
    virtual void w17() = 0;
    virtual void w18() = 0;
    virtual void fn54(int, int) = 0; // 0x54
};

struct Mods {
    void* pad00_0C[4];
    GroundModule* ground;   // 0x10
    SitModule* situation;   // 0x14
    void* pad18_60[19];
    SndModule* snd;         // 0x64
};

struct Holder {
    void* pad[0xD8 / 4];
    Mods* mods;             // 0xD8
};

extern "C" void fn_102_16A7C(Holder* h) {
    SndModule* snd = h->mods->snd;
    int ret = h->mods->situation->getKind();
    snd->fn60(2);
    int base = 0x22000000;
    snd->fn54(base + 0x10);
    snd->fn54(base + 0x11);
    h->mods->situation->setKind(2, 0);
    h->mods->ground->fn54(5, 0);
    if (ret != 2) {
        snd->fn50(base + 0x12);
        fn_102_169B4(h);
    } else {
        snd->fn54(base + 0x12);
    }
}
