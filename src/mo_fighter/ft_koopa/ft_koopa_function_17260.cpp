#pragma force_active on

extern "C" void fn_102_169B4(void* self);

struct WorkObj {
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
    virtual int isFlag(int) = 0;  // 0x4c
};

struct SitModule {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual int getKind() = 0;          // 0x14
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void setKind(int, int) = 0; // 0x20
};

struct Module70 {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m5(int, void*) = 0;    // 0x14
};

struct GroundData {
    int a;
    int b;
};

struct GroundModule : GroundData {
    virtual void g0() = 0;
    virtual void g1() = 0;
    virtual void g2() = 0;
    virtual void g3() = 0;
    virtual void g4() = 0;
    virtual void g5() = 0;
    virtual void g6() = 0;
    virtual void g7() = 0;
    virtual void g8() = 0;
    virtual void g9() = 0;
    virtual void g10() = 0;
    virtual void g11() = 0;
    virtual void g12() = 0;
    virtual void g13() = 0;
    virtual void g14() = 0;
    virtual void g15() = 0;
    virtual void g16() = 0;
    virtual void g17() = 0;
    virtual void g18() = 0;
    virtual void fn54(int, int) = 0;    // 0x54
};

struct Mods {
    void* pad00[4];         // 0x00
    GroundModule* ground;   // 0x10
    SitModule* sit;         // 0x14
    void* pad18[19];        // 0x18
    WorkObj* work;          // 0x64
    void* pad68[2];         // 0x68
    Module70* module70;     // 0x70
};

struct Holder {
    void* pad[0xD8 / 4];
    Mods* mods;             // 0xD8
};

extern "C" void fn_102_17260(void*, Holder* self) {
    int kind = self->mods->sit->getKind();
    WorkObj* work = self->mods->work;
    if (kind == 0) {
        if (work->isFlag(0x22000010) != 0) {
            fn_102_169B4(self);
            self->mods->module70->m5(0x11b, self);
            return;
        }
        self->mods->sit->setKind(2, 0);
        self->mods->ground->fn54(5, 0);
    }
}
