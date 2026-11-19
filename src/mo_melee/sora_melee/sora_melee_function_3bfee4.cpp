#include <mt/mt_vector.h>
#pragma force_active on

struct Flag { short m_value; Flag(short v) : m_value(v) { } };

class Sit { public: virtual void s0(); virtual void s1(); virtual void s2(); virtual int get(); };
class Kin { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void* getEnergy(int);
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual Vec2f getSumSpeed(Flag);
};
class Energy { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void resetEnergy(int, Vec2f*, Vec3f*, void*);
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
};
class Work { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void setInt(int, unsigned);
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float getFloat(unsigned);
    virtual void setFloat(unsigned, float);
    virtual void s14(); virtual void s15(); virtual void s16();
    virtual int isFlag(unsigned);
    virtual void onFlag(unsigned);
};
class M5c { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52();
    virtual void s53(); virtual void s54();
    virtual void f53(int, int, int, int);
    virtual void f54(int, int);
};
class M88 { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37();
    virtual void f38(int, float);
};
class M50 { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void f5(int, int, int, int);
    virtual void s6(); virtual void s7();
    virtual void f8(int, int, int);
};
class M4 { public:
    char pad[8];
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual Vec3f f25(int);
    virtual void s26(); virtual void s27(); virtual void s28();
    virtual void f29(int, Vec3f*);
};
class Mc { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8();
    virtual float f9();
};
struct VtPad { char p[0x3c]; };
class Vt : public VtPad { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual int f40();
};
struct Mods {
    char p0[4]; M4* m4; char p1[4]; Mc* mc; char p2[4]; Sit* sit;
    char p3[0x50 - 0x18]; M50* m50; char p4[4]; Work* dummy; M5c* m5c;
    char p5[4]; Work* work; char p6[0x7c - 0x68]; Kin* kin; char p7[0x88 - 0x80]; M88* m88;
};
struct Owner { char p[8]; Vt* b; char q[0xd8 - 0xc]; Mods* m; };

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_8080[];
float fn_27_192278(void*, unsigned long);
void fn_27_89DAC(int, void*);
}

extern "C" void fn_27_3BFEE4(void*, Owner* o) {
    const float* c = lbl_27_rodata_8080;
    if (o->m->sit->get() == 0) {
        Energy* e = (Energy*)__dynamic_cast(o->m->kin->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
        Vec3f zero;
        float x = o->m->work->getFloat(0x21000011) * c[0];
        zero.m_x = c[1];
        zero.m_y = c[1];
        zero.m_z = c[1];
        Vec2f speed(x, c[1]);
        e->resetEnergy(0x16, &speed, &zero, o);
        Vec2f speed2(x, c[1]);
        *(Vec2f*)((char*)e + 0x18) = speed2;
        e->s12();
        ((unsigned char*)e)[5] |= 0x80;
        Work* w = o->m->work;
        w->setFloat(0x21000008, fn_27_192278(o, 0xfa2));
        fn_27_89DAC(1, o);
    } else {
        Energy* stop = (Energy*)__dynamic_cast(o->m->kin->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
        Energy* grav = (Energy*)__dynamic_cast(o->m->kin->getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        Vec2f v;
        Vec2f::copy(v, o->m->kin->getSumSpeed(Flag(1)));
        Vec3f airZero(c[1], c[1], c[1]);
        stop->resetEnergy(6, &Vec2f(v.m_x, c[1]), &airZero, o);
        ((unsigned char*)stop)[5] |= 0x80;
        Vec3f gravZero(c[1], c[1], c[1]);
        grav->resetEnergy(0, &Vec2f(c[1], v.m_y), &gravZero, o);
        *(float*)((char*)grav + 0x10) = -fn_27_192278(o, 0xfa0);
        *(float*)((char*)grav + 0x1c) = fn_27_192278(o, 0xfa1);
        *(float*)((char*)grav + 0x14) = fn_27_192278(o, 0xfa1);
        ((unsigned char*)grav)[5] |= 0x80;
    }
    {
        Mods* m = o->m;
        Work* w = m->work;
        w->setInt(m->sit->get(), 0x20000008);
    }
    int kind = o->b->f40();
    int id = 4;
    if (kind == 5) id = 0x197;
    {
        Vec3f v = o->m->m4->f25(id);
        if (c[3] == o->m->mc->f9()) v.m_y = c[4]; else v.m_y = c[1];
        o->m->m4->f29(id, &v);
    }
    fn_27_89DAC(2, o);
    fn_27_89DAC(0, o);
    o->m->work->setInt(0, 0x2000000A);
    o->m->work->setInt(0, 0x2000000B);
    o->m->work->setInt(0, 0x2000000C);
    o->m->m5c->f54(9, -1);
    o->m->m5c->f53(2, 0, 1, -1);
    if (o->m->work->isFlag(0x22000013) == 0) {
        o->m->m88->f38(0x23, c[1]);
        o->m->work->onFlag(0x22000013);
    }
    if (o->b->f40() == 5) {
        o->m->m50->f8(0x1b18, 1, 0);
        o->m->m50->f5(0x1b15, 1, 1, 0);
    } else {
        o->m->m50->f8(0x17a1, 1, 0);
        o->m->m50->f8(0x9b5, 1, 0);
    }
}
