#pragma force_active on

class Vt {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8(float);
    virtual void s9();
    virtual void s10();
    virtual void s11(void*, void*);
    virtual void s12();
    virtual void s13(void*);
    virtual void s14();
    char pad[0xE0];
    void* fe4;
};

struct Ctx {
    char pad0[0x10];
    void* f10;
    void* f14;
};

struct GfAnim {
    char pad0[0xC];
    Vt* fc;
};

struct MuObj {
    char pad0[0x14];
    GfAnim* f14;
};

struct Self {
    Vt* f0;
    MuObj* f4;
    char pad1[0x64 - 8];
    Ctx* f64;
    char pad2[0x114 - 0x68];
    unsigned char f114;
};

extern float lbl_805A2748;
extern float lbl_805A274C;
extern "C" void fn_800B753C(void*, float);
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);
extern "C" void setFrameNode__8MuObjectFf(void*, float);

extern "C" {
void fn_800FF2C4(Self* self) {
    Ctx* ctx = self->f64;
    self->f0->s13(ctx->f10);
    if (self->f114 != 0) {
        self->f0->s11(self->f0->fe4, ctx->f10);
        fn_800B753C(ctx, lbl_805A2748);
        setUpdateRate__16gfModelAnimationFf(ctx->f14, lbl_805A274C);
    }
    MuObj* m = self->f4;
    setFrameNode__8MuObjectFf(m, lbl_805A2748);
    m->f14->fc->s8(lbl_805A274C);
}
}
