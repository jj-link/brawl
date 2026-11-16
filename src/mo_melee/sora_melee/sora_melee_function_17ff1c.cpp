#include <math.h>
#pragma force_active on

#define BF(v) (*(float*)&(v))
struct Vec2u {
    Vec2u() {}
    unsigned int x, y;
};
struct Vec3f { float x, y, z; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28(int, Vec3f*);
    virtual void slot29(int, Vec3f*);
};

struct Pad8 { int a, b; };
class Ctl8 : public Pad8 {
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
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual int s55(int, int);
    virtual void s56();
    virtual Vec2u s57(int, int);
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual Vec2u s63(int, int);
};

struct Modules {
    char pad0[0x10];
    Ctl8* ctl;
    char pad1[0x50];
    Object_vptr_0* m_64;
    char pad2[0x20];
    Object_vptr_0* m_88;
};
struct Accesser {
    char pad[0xd8];
    Modules* modules;
};
extern "C" const float lbl_27_rodata_2418;

extern "C" void fn_27_17FF1C(void*, Accesser* a) {
    Ctl8* ctl = a->modules->ctl;
    if (ctl->s55(8, 0) != 0) {
        Vec2u ve = ctl->s57(8, 0);
        float ax = BF(ve.x);
        float ay = BF(ve.y);
        float angle = (float)atan2(ax, ay);
        Vec2u vf = ctl->s63(8, 0);
        int h = a->modules->m_64->slot4(0x20000001);
        Vec3f p = {BF(vf.x), BF(vf.y), lbl_27_rodata_2418};
        a->modules->m_88->slot28(h, &p);
        Vec3f n = {lbl_27_rodata_2418, lbl_27_rodata_2418, -angle};
        a->modules->m_88->slot29(h, &n);
    }
}
