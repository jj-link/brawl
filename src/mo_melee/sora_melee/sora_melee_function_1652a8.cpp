#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Vec2 {
    unsigned int x;
    unsigned int y;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

class ObjA {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
    virtual Vec2 s13(short* out);
};

class ObjB {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13();
    virtual float s14(unsigned int a);
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18();
    virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22();
    virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26();
    virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30();
    virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38();
    virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42();
    virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46();
    virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54();
    virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58();
    virtual void s59(); virtual void s60(); virtual void s61(); virtual void s62();
    virtual void s63(); virtual void s64(); virtual void s65();
    virtual Vec3 s66(unsigned int a, void* holder);
};

class ObjC {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
    virtual void s13(unsigned int a, float b);
};

class ObjD {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8();
    virtual float s9();
};

struct Holder {
    char pad0[0x8];
    ObjB* b;
    ObjD* d;
    char pad1[0x54];
    ObjC* c;
    char pad2[0x14];
    ObjA* a;
};

struct Owner {
    char pad[0xd8];
    Holder* holder;
};

extern "C" {
extern const float lbl_27_rodata_200C;
}

extern "C" void fn_27_1652A8(Owner* self, unsigned int arg1, unsigned int arg2, unsigned int arg3,
                             unsigned int arg4, float farg0, float farg1) {
    short sp8 = 1;
    Vec2 v;
    v = self->holder->a->s13(&sp8);
    const Vec3& w = self->holder->b->s66(arg1, self->holder);
    float var = lbl_27_rodata_200C;
    float prod = farg1 * farg0;
    if (arg4 == 1) {
        if (*(float*)&v.x * self->holder->d->s9() < lbl_27_rodata_200C) {
            var = *(float*)&v.x / farg0;
        }
    } else {
        if (*(float*)&v.x * self->holder->d->s9() > lbl_27_rodata_200C) {
            var = *(float*)&v.x / farg0;
        }
    }
    self->holder->c->s13(arg2, var);
    float div = self->holder->b->s14(arg1);
    self->holder->c->s13(arg3, prod / ((float)(double)nw4r::ut::Abs(w.z) / div));
}
