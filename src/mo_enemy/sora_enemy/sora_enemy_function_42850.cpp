#pragma force_active on
extern "C" {
extern unsigned short lbl_41_data_DFFC[];
extern unsigned char  lbl_41_data_3E50[];
void fn_41_2D038(void* this_, unsigned a1, int a2, void* a3, void* a4);
}

struct P8 {
    virtual short m0() { return 0; }
    virtual short m1() { return 0; }
    virtual short m2() { return 0; }
    virtual short m3() { return 0; }
    virtual short m4() { return 0; }
    virtual short m5() { return 0; }
    virtual short m6() { return 0; }
    virtual short m7();
};

struct P {
    unsigned pad8[2];
    P8 d;
};

struct Mgr {
    char pad[0x80];
    P* p;
    char pad2[0x3C];
    int v;
};

struct Ctx {
    char pad[0xd8];
    Mgr* mgr;
};

struct Self {
    void* m0;
    int   m4;
};

struct L {
    int  x;
    int  y;
    int* px;
    int  v;
};

extern "C" void* fn_41_42850(Self* self, Ctx* ctx) {
    self->m0 = lbl_41_data_DFFC;
    int v = ctx->mgr->v;
    L l;
    l.x = 1;
    l.y = 0x29;
    l.px = &l.x;
    l.v = v;
    P* p = ctx->mgr->p;
    short sv = p->d.m7();
    fn_41_2D038(&self->m4, 1, (int)sv, &l.px, lbl_41_data_3E50);
    return self;
}
