#pragma force_active on

#include <types.h>
#include <mt/mt_vector.h>

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __memcpy(void*, const void*, unsigned long);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_8084;
extern const float lbl_27_rodata_8088;
float fn_27_192278(void*, unsigned long);
void fn_27_89DAC(int, void*);
}

struct Sub4Base {
    char pad[8];
};

class Sub4 : public Sub4Base {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20();
    virtual void s21(int);
    virtual void s22(); virtual void s23();
    virtual void s24(int, void*);
};

struct TaskABase {
    char pad[0x3c];
};

class TaskA : public TaskABase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual int s40();
};

class ObjA {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5();
    virtual void* s6(int);
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12();
    virtual Vec2f s13(short*);
};

class ObjC {
public:
    virtual void s0(); virtual void s1(); virtual void s2();
    virtual int s3();
};

class ObjD {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(unsigned long, void*, float);
    virtual void s14(); virtual void s15(); virtual void s16();
    virtual int s17(unsigned long);
    virtual void s18();
    virtual void s19(unsigned long);
};

class ObjE {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38();
    virtual void s39(int);
};

class EffA {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(int, Vec2f*, Vec3f*, void*);
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10();
    virtual void s11();
    virtual void s12();
    unsigned char pad4;
    unsigned char flags;
    char pad6[0xa];
    float f10;
    float f14;
    char pad18[4];
    float f1c;
};

class Owner {
public:
    char p0[4];
    Sub4* s4;
    char p1[0xc];
    ObjC* s14;
    char p2[0x4c];
    ObjD* s64;
    char p3[0x14];
    ObjA* s7c;
    char p4[8];
    ObjE* s88;
};

class Accesser {
public:
    char p0[8];
    TaskA* t8;
    char p1[0xcc];
    Owner* od8;
};

extern "C" void fn_27_3C5DEC(void* self, Accesser* acc) {
    short mask = 1;
    Vec2f speed;
    __memcpy(&speed, &acc->od8->s7c->s13(&mask), sizeof(speed));
    if (acc->od8->s14->s3() == 0) {
        EffA* stop = (EffA*)__dynamic_cast(acc->od8->s7c->s6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
        float fx = speed.m_x * fn_27_192278(acc, 0xFB4);
        Vec3f vz;
        vz.m_x = lbl_27_rodata_8084;
        vz.m_y = lbl_27_rodata_8084;
        vz.m_z = lbl_27_rodata_8084;
        stop->s5(0, &Vec2f(fx, lbl_27_rodata_8084), &vz, acc);
        stop->s12();
        stop->flags |= 0x80;
        fn_27_89DAC(1, acc);
    } else {
        EffA* stop = (EffA*)__dynamic_cast(acc->od8->s7c->s6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
        EffA* grav = (EffA*)__dynamic_cast(acc->od8->s7c->s6(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        float fx = speed.m_x * fn_27_192278(acc, 0xFB4);
        float fy = speed.m_y * fn_27_192278(acc, 0xFB5);
        Vec3f v3;
        v3.m_x = lbl_27_rodata_8084;
        v3.m_y = lbl_27_rodata_8084;
        v3.m_z = lbl_27_rodata_8084;
        stop->s5(6, &Vec2f(fx, lbl_27_rodata_8084), &v3, acc);
        stop->flags |= 0x80;
        Vec3f w3;
        w3.m_x = lbl_27_rodata_8084;
        w3.m_y = lbl_27_rodata_8084;
        w3.m_z = lbl_27_rodata_8084;
        grav->s5(0, &Vec2f(lbl_27_rodata_8084, fy), &w3, acc);
        grav->f10 = -fn_27_192278(acc, 0xFA0);
        grav->f1c = fn_27_192278(acc, 0xFA1);
        grav->f14 = fn_27_192278(acc, 0xFA1);
        grav->flags |= 0x80;
    }
    Vec3f param;
    param.m_x = lbl_27_rodata_8088;
    param.m_y = lbl_27_rodata_8088;
    param.m_z = lbl_27_rodata_8088;
    int stage = acc->t8->s40();
    acc->od8->s4->s24(stage == 5 ? 0x196 : 3, &param);
    stage = acc->t8->s40();
    acc->od8->s4->s21(stage == 5 ? 0x197 : 4);
    stage = acc->t8->s40();
    acc->od8->s4->s21(stage == 5 ? 0x196 : 3);
    float zero = lbl_27_rodata_8084;
    acc->od8->s64->s13(0x21000009, acc->od8, zero);
    fn_27_89DAC(2, acc);
    fn_27_89DAC(0, acc);
    if (acc->od8->s64->s17(0x22000013) != 0) {
        acc->od8->s88->s39(0x23);
        acc->od8->s64->s19(0x22000013);
    }
}
