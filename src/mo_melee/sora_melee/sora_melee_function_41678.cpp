#pragma force_active on
typedef unsigned int u32;

struct Src {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
    u32 f;
    float g;
    u32 h;
};

struct Sub {
    virtual void vf0();
    virtual u32* vf3(int);
};

struct Outer {
    u32 m0;
    u32 m4;
    u32 m8;
    u32 mC;
    u32 m10;
    u32 m14;
    u32 m18;
    u32 m1C;
    float m20;
    u32 m24;
    Sub sub;
};

extern "C" void fn_27_41678(Outer* self, const Src* src) {
    self->m8 = src->a;
    self->mC = src->b;
    self->m10 = src->c;
    self->m14 = src->d;
    self->m18 = src->e;
    self->m1C = src->f;
    self->m20 = src->g;
    self->m24 = src->h;
    u32* p = self->sub.vf3(3);
    *p = 1u << ((src->h >> 21) & 3);
}
