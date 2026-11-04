#pragma force_active on

#define V10(x) \
    virtual void x##0(); virtual void x##1(); virtual void x##2(); \
    virtual void x##3(); virtual void x##4(); virtual void x##5(); \
    virtual void x##6(); virtual void x##7(); virtual void x##8(); \
    virtual void x##9();

#define V100(x) \
    V10(x##0) V10(x##1) V10(x##2) V10(x##3) V10(x##4) \
    V10(x##5) V10(x##6) V10(x##7) V10(x##8) V10(x##9)

namespace {
struct Pad3C {
    char pad[0x3c];
};

class WorkModule {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int getInt(unsigned long);
    virtual void setInt(int, unsigned long);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(unsigned long, float);
};

class EffectModule {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int start(int, int, float*, float*, int, int, int, float, int);
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void stop(int, int, int);
};

struct Modules {
    char pad[0x64];
    WorkModule* work;
    char pad2[0x20];
    EffectModule* effect;
};

struct Accesser {
    char pad[8];
    void* cast;
    char pad2[0xcc];
    Modules* modules;
};

class CastObj : public Pad3C {
public:
    V100(a)
    V10(b0) V10(b1) V10(b2) V10(b3)
    V10(b4) V10(b5) V10(b6) V10(b7)
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void* target();
};
}

extern "C" {
float fn_27_192278(void*, unsigned long);
int fn_27_1922CC(void*, unsigned long);
int fn_27_3A33E4(void*, void*, float);
void* __dynamic_cast(void*, long, const void*, const void*, long);
unsigned int fn_27_111E30(void*);

extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
extern const float lbl_27_rodata_7E98;
extern const float lbl_27_rodata_7E9C;

void fn_27_3A25C8(void* self, Accesser* acc) {
    int r;
    WorkModule* work;
    int nw;
    {
        work = acc->modules->work;
        work->setFloat(0x11000013, fn_27_192278(acc, 0xfa4));
    }

    float f = acc->modules->work->getFloat(0x11000013);
    nw = fn_27_3A33E4(self, acc, f);
    acc->modules->effect->stop(0x10, 1, 1);

    CastObj* c = (CastObj*)__dynamic_cast(
        acc->cast, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);

    if (fn_27_111E30(c->target()) == 1) {
        acc->modules->work->setInt(-1, 0x10000040);
        acc->modules->work->setInt(-1, 0x10000041);
    } else {
        float z2 = fn_27_192278(acc, 0xfad);
        float y = fn_27_192278(acc, 0xfac);
        float x = fn_27_192278(acc, 0xfab);
        float z[3];
        float v[3];

        v[0] = x;
        v[1] = y;
        v[2] = z2;
        z[0] = lbl_27_rodata_7E98;
        z[1] = lbl_27_rodata_7E98;
        z[2] = lbl_27_rodata_7E98;

        EffectModule* e = acc->modules->effect;
        r = e->start(
            nw, fn_27_1922CC(acc, 0x5dc1), v, z, 0, 0x14, 0,
            lbl_27_rodata_7E9C, -1);
        acc->modules->work->setInt(nw, 0x10000040);
        acc->modules->work->setInt(r, 0x10000041);
    }
}
}
