#pragma force_active on

struct Vec2f { float x; float y; };
struct Vec3f { float x; float y; float z; };
struct IntPair { int a; int b; };
union PairUnion { IntPair ip; Vec2f fp; };

#define V9(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); \
    virtual void p##3(); virtual void p##4(); virtual void p##5(); \
    virtual void p##6(); virtual void p##7(); virtual void p##8();
#define V10(p) V9(p) virtual void p##9();

class ObjA {
public:
    V9(t0)
    virtual int f9(int a, int b, void* c, void* d, int e);
};
class Hdr {
public:
    int h0;
    int h1;
};
class Inner {
public:
    char pad[0xC];
    void* unkC;
};
class Mid {
public:
    char pad[0xD8];
    Inner* unkD8;
};
class Self : public Hdr {
public:
    V9(s0)
    virtual int f9(void* a, int c);
    V10(s1)
    V10(s2)
    V10(s3)
    V10(s4)
    V10(s5)
    V10(s6)
    V10(s7)
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual IntPair f86(int arg);
    char pad1[0x44 - 0xC];
    ObjA* unk44;
    char pad2[0x54 - 0x48];
    Mid* unk54;
};

extern const float lbl_27_rodata_3C4;

extern "C" int fn_27_2E518(Self* self, int arg1, int arg2, int arg3) {
    ObjA* o = self->unk44;
    int r31 = o->f9(arg2, arg1, self->unk54->unkD8->unkC, self, arg3);
    PairUnion u;
    u.ip = self->f86(arg3);
    Vec3f p;
    p.y = u.fp.y;
    p.x = u.fp.x;
    p.z = lbl_27_rodata_3C4;
    self->f9(&p, arg3);
    return r31;
}