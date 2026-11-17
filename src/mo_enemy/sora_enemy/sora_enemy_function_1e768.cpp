#include <types.h>
#include <mt/mt_vector.h>
#include <mt/mt_matrix.h>
#pragma force_active on

struct VObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual Vec3f slot14(int);
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned long);
    virtual float slot18();
};

struct Modules {
    char pad0[0xC];
    VObj* unkC;
    char pad1[0x64 - 0x10];
    VObj* unk64;
};

struct Ent {
    char pad0[0x8];
    void* unk8;
    char pad1[0xD8 - 0xC];
    Modules* unkD8;
};

extern "C" const float lbl_41_rodata_C90[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" {
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
void fn_41_534C(Vec3f*, const Vec3f*);
void fn_41_6354(Vec3f*, float);
void fn_41_6168(Vec3f*, void*, float, int);
void fn_41_6270(Vec3f*, void*, float, int);
void fn_41_4D14(Vec3f*, const Vec3f*, const Vec3f*);
void fn_8003ECA0(Matrix*, float, float, float);
void fn_8003EA9C(Matrix*, float);
void fn_8003EBF4(Matrix*, float);
}

extern "C" void fn_41_1E768(Vec3f* arg0, Ent* arg1, int arg2, float farg0, int arg3, unsigned long arg4) {
    Matrix m20C(true);
    Matrix m1DC(true);
    Matrix m1AC(true);
    Matrix m17C(true);
    Matrix m14C(true);
    Matrix m11C(true);
    Matrix mEC(true);
    Matrix mBC(true);
    const float* c = lbl_41_rodata_C90;
    fn_41_5AC4(arg0, c[3], c[3], c[3]);
    VObj* a = arg1->unkD8->unkC;
    void* enemy = __dynamic_cast(arg1->unk8, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    Vec3f b0 = a->slot14(arg3);
    Vec3f a4;
    Vec3f a98;
    Vec3f v8C;
    Vec3f v80;
    Vec3f v74;

    if ((unsigned long)(arg2 - 2) <= 2UL) {
        fn_41_6270(&a4, enemy, a->slot18(), arg1->unkD8->unk64->slot17(0x12000003));
        if (arg3 == 0) {
            Vec3f a68;
            fn_41_6168(&a68, enemy, a->slot18(), arg1->unkD8->unk64->slot17(0x12000003));
            fn_41_534C(&a4, &a68);
        }
        Vec3f a5c;
        fn_41_534C(&a5c, &a4);
        fn_41_6354(&a5c, c[19]);
        fn_8003ECA0(&m20C, a5c.m_x, a5c.m_y, a5c.m_z);
        m20C.inverse(&m11C);
        Vec3f a50;
        fn_41_534C(&a50, &b0);
        fn_41_6354(&a50, c[19]);
        fn_8003ECA0(&m1DC, a50.m_x, a50.m_y, a50.m_z);
        fn_41_534C(&a98, &b0);
        fn_41_6354(&a98, c[19]);
        Vec3f a44;
        fn_41_5AC4(&a44, c[3], c[3], c[3]);
        fn_8003ECA0(&m1AC, a44.m_x, a44.m_y, a44.m_z);

        if (arg2 == 2) {
            if (arg4 == 1UL) {
                float f0 = (c[14] == a->slot18()) ? c[0] : c[12];
                fn_8003EBF4(&m1AC, c[20] * (farg0 * f0));
            } else {
                fn_8003EBF4(&m1AC, c[20] * farg0);
            }
        } else if (arg2 == 3) {
            if (arg4 == 1UL) {
                float f0 = (c[14] == a->slot18()) ? c[0] : c[12];
                fn_8003EA9C(&m1AC, c[20] * (farg0 * f0));
            } else {
                fn_8003EA9C(&m1AC, c[20] * farg0);
            }
        } else if (arg2 == 4) {
            if (arg4 == 1UL) {
                float f0 = (c[14] == a->slot18()) ? c[0] : c[12];
                m1AC.rotY(c[20] * (farg0 * f0));
            } else {
                m1AC.rotY(c[20] * farg0);
            }
        }

        m20C.mul(&m1DC, &m17C);
        m1AC.mul(&m17C, &m14C);
        m11C.mul(&m14C, &mEC);
        mEC.getRotate(&v8C);
        Vec3f v38;
        fn_41_4D14(&v38, &v8C, &a98);
        fn_41_534C(arg0, &v38);
        Vec3f v2C = *arg0;
        fn_41_6354(&v2C, c[28]);
        fn_41_534C(arg0, &v2C);
        return;
    }

    Vec3f a20;
    fn_41_534C(&a20, &b0);
    fn_41_6354(&a20, c[19]);
    fn_8003ECA0(&mBC, a20.m_x, a20.m_y, a20.m_z);
    mBC.getRotate(&v80);
    if (arg2 == 5) {
        fn_8003EA9C(&mBC, c[20] * farg0);
    } else if (arg2 == 6) {
        mBC.rotY(c[20] * farg0);
    } else if (arg2 == 7) {
        fn_8003EBF4(&mBC, c[20] * farg0);
    } else {
        return;
    }
    mBC.getRotate(&v74);
    Vec3f v14;
    fn_41_4D14(&v14, &v74, &v80);
    fn_41_534C(arg0, &v14);
    Vec3f v8 = *arg0;
    fn_41_6354(&v8, c[28]);
    fn_41_534C(arg0, &v8);
}
