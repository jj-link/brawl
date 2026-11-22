#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_327E0C(void* self, int a, void* b, const void* c, int d, float e);
void fn_27_328378(void* self, const void* arg, const void* v, int flag, float scale);
extern char lbl_27_data_86A80[];
extern char lbl_27_data_248[];
extern float lbl_27_rodata_7590[];
}

#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();

#include <mt/mt_vector.h>
struct Pad8 { char pad[8]; };

class HObj;
class F2Obj;

class PObj {
public:
    V8(a) virtual void a8();
    virtual float f11(void* d);
};

class QObj : public Pad8 {
public:
    V8(a) V8(b) V8(c) V8(d) virtual void e0(); virtual void e1(); virtual void e2();
    virtual Vec3f getA(int);
    V8(f) V8(g) virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4();
    virtual Vec2f getB(int, int);
};

inline void getVec(QObj* q, Vec2f& out) { Vec2f::copy(out, q->getB(0xff, 0)); }

class GObj : public Pad8 {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual HObj* getH();
};

class FObj {
public:
    virtual void a0(); virtual void a1();
    virtual F2Obj* f4(void* e, void* d);
};

class F2Obj {
public:
    virtual void a0(); virtual void a1();
    virtual int f4();
};

class HObj {
public:
    V8(a) virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void* f14();
};

struct EObj { char pad[0x28]; int unk28; };

struct DObj {
    GObj* g;
    int pad4[2];
    PObj* p;
    QObj* q;
    int pad14;
    FObj* f;
};

struct Ctx {
    char p0[8];
    EObj* e;
    char p1[0xcc];
    DObj* d;
};

extern "C" int fn_27_32625C(void* self, Ctx* ctx) {
    const float* k = lbl_27_rodata_7590;
    if (__dynamic_cast(ctx->e, 0x3c, lbl_27_data_86A80, lbl_27_data_248, 0) == 0) {
        return 0;
    }
    DObj* d = ctx->d;
    QObj* q = d->q;
    float f = d->p->f11(d);
    Vec3f a = q->getA(0);
    Vec2f v;
    getVec(q, v);
    if (k[4] <= v.m_y && v.m_y <= k[5]) {
        f *= k[0];
    }
    d = ctx->d;
    EObj* e = ctx->e;
    FObj* ff = d->f;
    GObj* g = d->g;
    int f3;
    int e28 = e->unk28;
    F2Obj* f2 = ff->f4(e, d);
    f3 = f2->f4();
    HObj* h = g->getH();
    void* i = h->f14();
    fn_27_327E0C(self, e28, i, &a, f3, f);
    fn_27_328378(self, &a, &v, 1, f);
    return 0;
}
