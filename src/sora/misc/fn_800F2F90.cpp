#pragma force_active on

struct Vt {
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
    char pad[0xE0];
    void* fe4;
};

struct Res {
    char pad[8];
    Vt* f8;
    Vt* fc;
    char pad2[8];
    Vt* f18;
};

struct MuObj {
    char pad[0x10];
    void* f10;
    Res* f14;
};

struct Self {
    char pad[0x40];
    Vt* f40;
    MuObj* f44;
    MuObj* f48;
    char pad2[0xA4 - 0x4C];
    int fa4;
    char pad3[0xD0 - 0xA8];
    int fd0;
};

struct Rec { char pad[0x28]; unsigned char f28; };

extern "C" {
void setFrameNode__8MuObjectFf(void*, float);
void setFrameMatCol__8MuObjectFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
void fn_800B7414(void*, const char*, int, int, int);
Rec* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
extern void* g_GameGlobal;
extern char lbl_8045B8DC[];
extern float lbl_805A25C0;
extern float lbl_805A25D4;
extern float lbl_805A25FC;
extern float lbl_805A2600;

void fn_800F2F90(Self* self) {
    MuObj* m = self->f44;
    self->f40->s13(m->f10);
    self->f40->s11(self->f40->fe4, m->f10);
    setFrameNode__8MuObjectFf(m, lbl_805A25FC);
    setFrameMatCol__8MuObjectFf(m, lbl_805A25FC);
    m->f14->fc->s8(lbl_805A25D4);
    m->f14->f18->s8(lbl_805A25D4);
    MuObj* n = self->f48;
    float f;
    if (self->fd0 != 1) {
        fn_800B7414(n, lbl_8045B8DC, self->fa4, 0xA0, 0x78);
        f = (float)(unsigned int)((getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal)->f28 >> 7) & 1);
    } else {
        f = lbl_805A2600;
    }
    setFrameVisible__8MuObjectFf(n, f);
    n->f14->f8->s8(lbl_805A25C0);
}
}
