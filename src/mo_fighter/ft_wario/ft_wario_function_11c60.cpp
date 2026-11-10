#pragma force_active on
struct V3 {
    int x, y, z;
};

struct Flags {
    unsigned char a : 1, b : 1, c : 1, d : 1;
    unsigned char e : 1, f : 1, g : 1, h : 1;
    union {
        struct {
            unsigned char ij : 2, rest : 6;
        } bits;
        struct {
            unsigned char i : 1, j : 1, rest : 6;
        } single;
    };
};

struct Param {
    int resource, team, owner, another, index, owner2;
    int r0, r1;
    V3 pos;
    float facing;
    int parameter, r2, situation, status, r3, motion, r4;
    Flags flags;
};

#define D1(n) virtual void n();
#define D4(n) D1(n##a) D1(n##b) D1(n##c) D1(n##d)
#define D16(n) D4(n##a) D4(n##b) D4(n##c) D4(n##d)

struct Extra {
    int kind;
    bool flag;
    void* obj;

    Extra(int k, bool f, void* object) : kind(k), flag(f), obj(object) {}
};

struct Obj;

struct M54 {
    D1(a0) D1(a1) D1(a2) D1(a3)
    virtual void f18(int, void*);
    D4(b) D1(c0) D1(c1) D1(c2) D1(c3) D1(c4) D1(c5)
    virtual void f44(int, Extra*);
    D16(d) D16(e) D16(f) D16(g)
    D1(h0) D1(h1) D1(h2) D1(h3) D1(h4)
    D4(z0) D4(z1) D4(z2) D1(zz0) D1(zz1)
    virtual void f194(int, int, bool);

    void finishInitialize(int team, void* arg2, Obj& o);
};

struct M64 {
    D1(a0) D1(a1) D1(a2) D1(a3) D1(a4)
    virtual void f1c(int, int);
    D4(b0) D4(b1) D4(b2)
    virtual void f50(int);
};

struct M7c {
    D4(a) D4(b) D1(c0) D1(c1) D1(c2) D1(c3)
    virtual void f38();
};

struct Pad8 {
    int a, b;
};

struct M38 : Pad8 {
    D16(a) D4(b) D4(c) D4(d)
    virtual void f78(int);
};

struct Pad8b {
    int a, b;
};

struct M10 : Pad8b {
    D16(a) D16(b) D16(c)
    virtual void fc8(int, int);
};

struct Acc {
    char p0[0x10];
    M10* m10;
    char p1[0x38 - 0x14];
    M38* m38;
    char p2[0x54 - 0x3c];
    M54* m54;
    char p3[0x64 - 0x58];
    M64* m64;
    char p4[0x7c - 0x68];
    M7c* m7c;
};

struct Inner {
    char pad[0xd8];
    Acc* acc;
};

struct Obj {
    char p0[0x28];
    void* field28;
    char p1[0x60 - 0x2c];
    Inner* inner;
    char p2[0xbc - 0x64];
    int* value;
};

extern "C" void fn_27_1D8370(void*, const Param*);
extern "C" void* __memcpy(void*, const void*, unsigned long);

inline void M54::finishInitialize(int team, void* arg2, Obj& o) {
    f194(3, 3, 0);
    f194(3, 4, 1);
    f194(3, 0, 1);
    f194(3, 1, 1);
    f194(3, 15, 1);

    o.inner->acc->m64->f50(0x12000000);
    o.inner->acc->m64->f1c(team, 0x10000006);
    o.inner->acc->m64->f1c(*o.value + 1, 0x10000005);
    o.inner->acc->m7c->f38();

    Extra x(0x45c, false, o.field28);
    f18(5, arg2);
    f44(5, &x);

    o.inner->acc->m38->f78(1);
    o.inner->acc->m10->fc8(1, 0);
}

inline void initializeParam(
    Param& p, Obj& o, int resource, int team, int parameter,
    V3* pos, float facing
) {
    p.resource = resource;
    p.team = team;
    p.owner = team;
    p.another = team;
    p.index = -1;
    p.owner2 = -1;
    p.r0 = 0;
    p.r1 = 0;
    __memcpy(&p.pos, pos, sizeof(V3));
    p.facing = facing;
    p.parameter = parameter;
    p.r2 = 0;
    p.situation = 2;
    p.status = 0x80;
    p.r3 = 0;
    p.r4 = 0;
    p.flags.a = 1;
    p.flags.b = 1;
    p.flags.c = 0;
    p.flags.d = 0;
    p.flags.e = 1;
    p.flags.f = 0;
    p.flags.g = 0;
    p.flags.h = 0;
    p.flags.bits.ij = 0;
    p.flags.single.i = 1;
    p.motion = 0x50;
    fn_27_1D8370(&o, &p);
}

extern "C" void fn_110_11C60(
    Obj& o, int resource, void* arg2, int team, int parameter,
    V3* pos, float facing
) {
    Param p;
    initializeParam(p, o, resource, team, parameter, pos, facing);
    o.inner->acc->m54->finishInitialize(team, arg2, o);
}
