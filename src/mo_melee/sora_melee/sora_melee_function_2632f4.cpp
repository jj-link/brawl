#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>

class VObj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2(int, unsigned int, float, float, float);
    virtual int s3();
    virtual void s4();
    virtual void s5(int);
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
    virtual float s22();
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
    virtual void s40(int, unsigned int);
};

struct ModA {
    char pad0[0xC];
    VObj* f_c;
    char pad10[0x4];
    VObj* f_b;
    char pad18[0x8];
    VObj* f_d;
};

class StageObject {
public:
    char pad0[0x74];
    float unk74;
    char pad78[0x108];
    ModA* unk180;
    char pad184[4];
    unsigned int* unk188;
    char pad18C[0x1B4];
    VObj unk340;
    void activate(float, float, Vec3f*, bool);
};

extern "C" float lbl_27_rodata_42C0;

extern "C" void fn_27_2632F4(StageObject* arg0, Vec3f* arg1, float farg0, float farg1) {
    arg0->activate(farg0, farg1, arg1, false);
    arg0->unk74 = lbl_27_rodata_42C0;
    int r31 = arg0->unk180->f_b->s3();
    float f31 = arg0->unk180->f_c->s22();
    unsigned int i = 1;
    while (i < *arg0->unk188) {
        arg0->unk180->f_d->s2(r31, i, arg1->m_x, f31, farg0);
        i++;
    }
    int r30 = -1;
    if (r31 == 0) {
        r30 = 2;
    } else if (r31 == 2) {
        r30 = 0;
    }
    unsigned int j = 0;
    while (j < *arg0->unk188) {
        arg0->unk180->f_d->s40(r30, j);
        j++;
    }
    arg0->unk340.s5(8);
}
