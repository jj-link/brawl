#include <types.h>
#include <math.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_2408;
}

#define BF(v) (*(float*)&(v))

struct Vec2u {
    Vec2u() {}
    unsigned int x, y;
};
struct Vec3f { float x, y, z; };

class Obj0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(unsigned int);
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual float s12(unsigned int);
    virtual void s13(unsigned int, float);
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual float s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28(int, Vec3f*);
    virtual void s29(int, Vec3f*);
};

struct Pad8 { int a; int b; };

class Ctl8 : public Pad8 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56();
    virtual Vec2u s57(int, int);
    virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61();
    virtual void s62();
    virtual Vec2u s63(int, int);
    virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67();
    virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
    virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82();
    virtual Vec2u s83(int);
    virtual Vec2u s84(int);
    virtual Vec2u s85(int);
    virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93();
    virtual void s94(); virtual void s95(); virtual void s96(); virtual void s97();
    virtual void s98(); virtual void s99(); virtual void s100(); virtual void s101();
    virtual void s102(); virtual void s103();
    virtual void s104(int, float);
};

struct Modules {
    char pad0[0xc];
    Obj0* m_c;
    Ctl8* ctl;
    char pad1[0x50];
    Obj0* m_64;
    char pad2[0x20];
    Obj0* m_88;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_17FA30(void*, Accesser* a) {
    Ctl8* ctl = a->modules->ctl;
    Vec2u va = ctl->s85(0);
    Vec2u vb = ctl->s84(0);
    Vec2u vc = ctl->s83(0);
    float f31 = a->modules->m_64->s12(0x21000005);
    float f30 = BF(va.y);
    f30 = (f30 < BF(vb.y)) ? f30 : BF(vb.y);
    float f29 = f31 + a->modules->m_64->s12(0x21000004);
    f31 = a->modules->m_c->s22();
    if (f31 + (BF(vc.y) + f29) > f30) {
        f29 = f30 - (BF(vc.y) + f31);
    }
    Vec2u ve = a->modules->ctl->s57(8, 0);
    float ax = BF(ve.x);
    float ay = BF(ve.y);
    float angle = (float)atan2(ax, ay);
    Vec2u vf = a->modules->ctl->s63(8, 0);
    int h = a->modules->m_64->s4(0x20000001);
    Vec3f p = {BF(vf.x), BF(vf.y), lbl_27_rodata_2408};
    a->modules->m_88->s28(h, &p);
    Vec3f n = {lbl_27_rodata_2408, lbl_27_rodata_2408, -angle};
    a->modules->m_88->s29(h, &n);
    a->modules->m_64->s13(0x21000005, f29);
    ctl->s104(0, f29 / f31);
}
