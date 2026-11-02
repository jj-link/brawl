#pragma force_active on

#define V10(x) virtual void x##0(); virtual void x##1(); virtual void x##2(); virtual void x##3(); virtual void x##4(); virtual void x##5(); virtual void x##6(); virtual void x##7(); virtual void x##8(); virtual void x##9();
#define V100(x) V10(x##0) V10(x##1) V10(x##2) V10(x##3) V10(x##4) V10(x##5) V10(x##6) V10(x##7) V10(x##8) V10(x##9)

namespace {
struct Pad8 { char pad[8]; };
struct Pad3C { char pad[0x3c]; };

class CheckA {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8();
    virtual int check();
};

class CheckB : public Pad8 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13();
    virtual int check();
};

class WorkModule {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual int getInt(unsigned long id);
    virtual void setInt(int v, unsigned long id);
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11();
    virtual float getFloat(unsigned long id);
};

class EffectModule {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10();
    virtual int start(int a, int b, float* pos, float* rot, int c, int d, int e, float scale, int f);
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21();
    virtual void stop(int id, int a, int b);
};

struct Modules {
    char pad0[0x44];
    CheckA* a;
    char pad1[0x1C];
    WorkModule* work;
    char pad2[0x20];
    EffectModule* effect;
    char pad3[0x2C];
    CheckB* b;
};

struct Accesser {
    char pad[8];
    void* cast;
    char pad2[0xCC];
    Modules* modules;
};

class CastObj : public Pad3C {
public:
    V100(a) V10(b0) V10(b1) V10(b2) V10(b3) V10(b4) V10(b5) V10(b6) V10(b7)
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4();
    virtual void target();
};
}

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
int fn_27_3A33E4(void*, void*, float);
void* __dynamic_cast(void*, long, const void*, const void*, long);
unsigned int fn_27_111E30();
float fn_27_192278(void*, int);
int fn_27_1922CC(void*, int);
extern void* lbl_27_bss_F0;
extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
extern const float lbl_27_rodata_7E98;
extern const float lbl_27_rodata_7E9C;

void fn_27_3A2A1C(void* self, Accesser* acc) {
    if (lbl_27_bss_F0 == 0) {
        void* s = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (s != 0) {
            s = fn_27_5BCD0(s);
        }
        lbl_27_bss_F0 = s;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1) {
        if (acc->modules->a->check() == 0) {
            if (acc->modules->b->check() == 0) {
                float f = acc->modules->work->getFloat(0x11000013);
                int old = acc->modules->work->getInt(0x10000040);
                int nw = fn_27_3A33E4(self, acc, f);
                CastObj* c = (CastObj*)__dynamic_cast(acc->cast, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
                c->target();
                if (fn_27_111E30() != 1 && old != nw) {
                    if (acc->modules->work->getInt(0x10000041) >= 0) {
                        acc->modules->effect->stop(acc->modules->work->getInt(0x10000041), 1, 1);
                        acc->modules->work->setInt(-1, 0x10000041);
                    }
                    float z2 = fn_27_192278(acc, 0xFAD);
                    float y = fn_27_192278(acc, 0xFAC);
                    float x = fn_27_192278(acc, 0xFAB);
                    float z[3];
                    float v[3];
                    v[0] = x;
                    v[1] = y;
                    v[2] = z2;
                    z[0] = lbl_27_rodata_7E98;
                    z[1] = lbl_27_rodata_7E98;
                    z[2] = lbl_27_rodata_7E98;
                    EffectModule* e = acc->modules->effect;
                    int r = e->start(nw, fn_27_1922CC(acc, 0x5DC1), v, z, 0, 0x14, 0, lbl_27_rodata_7E9C, -1);
                    acc->modules->work->setInt(nw, 0x10000040);
                    acc->modules->work->setInt(r, 0x10000041);
                }
            }
        }
    }
}
}
