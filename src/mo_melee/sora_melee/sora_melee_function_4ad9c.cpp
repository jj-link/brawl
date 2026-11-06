#pragma force_active on

struct Ret {
    int pad0;
    int v4;
};

class Sub {
public:
    virtual void slot0();
    virtual Ret* slot1(int);
};

struct Src {
    unsigned int a0;
    unsigned int a4;
    unsigned int a8;
    float aC;
    unsigned int a10;
    unsigned int a14;
};

struct Self {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
    float f10;
    unsigned int f14;
    unsigned int f18;
    Sub sub;
};

struct Out {
    char pad[0x1c];
    void* p;
};

extern "C" void fn_27_4AD9C(Self* self, const Src* src, Out* out) {
    self->f4 = src->a0;
    self->f8 = src->a4;
    self->fC = src->a8;
    self->f10 = src->aC;
    self->f14 = src->a10;
    self->f18 = src->a14;
    self->f0 = 1;

    Ret* r;
    r = self->sub.slot1(0);
    r->v4 = 2;
    r = self->sub.slot1(1);
    r->v4 = (self->f14 >> 4) & 0x3FF;
    r = self->sub.slot1(2);
    r->v4 = (self->f14 >> 1) & 7;
    r = self->sub.slot1(3);
    r->v4 = self->f18 >> 28;
    r = self->sub.slot1(4);
    r->v4 = 1;

    out->p = &self->sub;
}
