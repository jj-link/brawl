#pragma force_active on

extern "C" {
extern char lbl_804666F8[];
extern unsigned int lbl_8040AF40[6];
void fn_801C05C0(void* self, void* data, int a, int b, int c, int d, int e);
}

struct Blk {
    unsigned int w[6];
};

struct Obj {
    void* vt;
    int m4;
    int m8;
    char mC;
    int m10;
    int m14;
};

extern "C" Obj* fn_801C03DC(Obj* self) {
    Blk blk;
    Blk* src = reinterpret_cast<Blk*>(lbl_8040AF40);
    unsigned int w0, w1, w2, w3, w4, w5;
    self->m4 = 0;
    self->m8 = 0;
    self->vt = lbl_804666F8;
    self->mC = 0;
    self->m10 = 0;
    self->m14 = 0;
    w0 = src->w[0];
    w1 = src->w[1];
    w2 = src->w[2];
    w3 = src->w[3];
    w4 = src->w[4];
    w5 = src->w[5];
    blk.w[0] = w0;
    blk.w[1] = w1;
    blk.w[2] = w2;
    blk.w[3] = w3;
    blk.w[4] = w4;
    blk.w[5] = w5;
    fn_801C05C0(self, &blk, w4, w3, w2, w1, w0);
    return self;
}
