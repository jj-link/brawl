#include <mt/mt_vector.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_7F90[];
extern "C" float rsqrtf__Ff(float);

class ModA {
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
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int s17(int);
    virtual void s18(int);
};

class ModB {
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
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual Vec3f s14(int);
    virtual void s15(Vec3f*, int);
};

class ModC {
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
    virtual void s11();
    virtual void s12();
    virtual nw4r::math::_VEC2 s13(short*);
};

struct Mods {
    char p0[0x0c];
    ModB* b;
    char p1[0x64 - 0x10];
    ModA* a;
    char p2[0x7c - 0x68];
    ModC* c;
};

struct Owner {
    char p0[0xd8];
    Mods* mods;
};

struct S {
    char p0[0x28];
    float f28;
    float f2c;
    float f30;
};

struct Self {
    char p0[4];
    S* s;
    float f8;
};

extern "C" void fn_27_3B0DC4(Self* self, Owner* owner) {
    const float* lbl = lbl_27_rodata_7F90;

    if (owner->mods->a->s17(0x22000003) == 0) {
        owner->mods->a->s18(0x22000003);
        return;
    }
    if (owner->mods->a->s17(0x22000001) != 0) {
        Vec3f sp30 = owner->mods->b->s14(1);
        self->f8 = self->f8 + self->s->f30;
        sp30.m_x = sp30.m_x + self->f8;
        if (sp30.m_x > lbl[1]) {
            sp30.m_x = lbl[1];
            owner->mods->a->s18(0x22000002);
        }
        owner->mods->b->s15(&sp30, 1);
        return;
    }
    if (owner->mods->a->s17(0x22000002) != 0) {
        return;
    }
    short sp8 = -1;
    nw4r::math::_VEC2 v = owner->mods->c->s13(&sp8);
    float d = v.x * v.x + v.y * v.y;
    float len;
    if ((float)fabs(d) <= lbl[3]) {
        len = lbl[2];
    } else {
        len = d * rsqrtf__Ff(d);
    }
    if (len < self->s->f28) {
        owner->mods->a->s18(0x22000001);
        Vec3f sp24 = owner->mods->b->s14(1);
        Vec3f sp18 = owner->mods->b->s14(0);
        sp24.m_z = sp18.m_z;
        owner->mods->b->s15(&sp24, 1);
        self->f8 = self->s->f2c;
    }
}
