#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

#define VP1(x) virtual void x();
#define VP2(x) VP1(x##0) VP1(x##1)
#define VP4(x) VP2(x##0) VP2(x##1)
#define VP8(x) VP4(x##0) VP4(x##1)
#define VP16(x) VP8(x##0) VP8(x##1)
#define VP32(x) VP16(x##0) VP16(x##1)
#define VP64(x) VP32(x##0) VP32(x##1)

struct VBase8 {
    char pad[8];
};

struct UnkC {
    VP4(a)
    virtual Vec3f m5();
};

struct Unk64 {
    VP4(a) VP1(b)
    virtual void m6(int, int);
    VP4(c) VP2(d) VP1(e)
    virtual void m14(float, int);
};

struct Unk7C {
    VP4(a) VP2(b)
    virtual void* m7(int);
};

struct Unk14 {
    VP4(a) VP2(b)
    virtual void m7(int, bool);
};

struct Unk54 {
    VP8(a)
    virtual void m9(int);
    virtual unsigned int m10(int);
    VP64(c) VP8(d) VP4(e) VP2(f)
    virtual unsigned int m89();
};

struct ObjA : VBase8 {
    VP16(a) VP2(b) VP1(c)
    virtual void m20(int, int);
    VP32(d) VP2(e) VP1(f)
    virtual unsigned int m56(int, int);
    VP32(g) VP16(h) VP4(i) VP2(j) VP1(k)
    virtual float m112();
};

struct Floats {
    float f0;
    char pad[0x20];
    float f24;
    float f28;
};

struct Eff {
    char p0[5];
    unsigned char flags;
    char p6[2];
    float x, y, z;
};

struct D8 {
    char p0[0xC];
    UnkC* pC;
    ObjA* p10;
    Unk14* p14;
    char p1[0x54 - 0x18];
    Unk54* p54;
    char p2[0x64 - 0x58];
    Unk64* p64;
    char p3[0x7C - 0x68];
    Unk7C* p7c;
};

struct Acc {
    char p0[0xD8];
    D8* d8;
    UnkC& posture() const { return *d8->pC; }
};

struct Self {
    char p0[0x60];
    Acc* acc;
    char p1[0x23E8 - 0x64];
    Floats* f23e8;
};

extern "C" void fn_122_1AF04(void*);
extern "C" void fn_122_1B000(void*);
extern "C" void fn_122_D580(float*, float, float, float);
extern "C" void fn_27_89544(void*, int);
extern "C" float randf__Fv();
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const unsigned char lbl_122_data_81AC[];
extern const unsigned char lbl_122_data_DF08[];
extern const unsigned char lbl_122_data_E1EC[];
extern const float lbl_122_rodata_A8;

extern "C" void fn_122_17ED8(Self* self, int arg1, int arg2) {
    switch (arg1) {
    case 1: {
        Unk64* u = self->acc->d8->p64;
        u->m14(self->f23e8->f24, 0x21000000);
        self->acc->d8->p64->m6(-1, 0x20000000);
        break;
    }
    case 2: {
        Unk64* u = self->acc->d8->p64;
        u->m14(self->f23e8->f28, 0x21000000);
        self->acc->d8->p64->m6(-1, 0x20000000);
        break;
    }
    case 5:
        switch (arg2) {
        case 0:
            if (self->acc->d8->p54->m89() == 1) {
                fn_122_1AF04(self->acc);
            }
            if (self->acc->d8->p10->m56(8, 0) == 1) {
                Vec3f pos = self->acc->posture().m5();
                pos.m_z = self->acc->d8->p10->m112();
                fn_122_1B000(self->acc);
                self->acc->d8->p14->m7(0, false);
                self->acc->d8->p10->m20(1, 0);
            }
            break;
        }
        break;
    case 0:
        switch (arg2) {
        case 4:
            if (self->acc->d8->p54->m89() == 1) {
                fn_122_1AF04(self->acc);
            }
            if (self->acc->d8->p54->m10(3) == 1) {
                self->acc->d8->p54->m9(3);
            }
            break;
        }
        {
            Eff* e1 = (Eff*)__dynamic_cast(self->acc->d8->p7c->m7(1), 0, lbl_122_data_E1EC, lbl_122_data_81AC, 0);
            Eff* e2 = (Eff*)__dynamic_cast(self->acc->d8->p7c->m7(2), 0, lbl_122_data_DF08, lbl_122_data_81AC, 0);
            if (e1 != 0 && e2 != 0) {
                e2->x = self->f23e8->f0;
                e2->flags |= 0x80;
                float y;
                float z;
                z = lbl_122_rodata_A8 * randf__Fv();
                y = lbl_122_rodata_A8 * randf__Fv();
                Vec3f v;
                fn_122_D580(&v.m_x, lbl_122_rodata_A8 * randf__Fv(), y, z);
                e1->x = v.m_x;
                e1->y = v.m_y;
                e1->z = v.m_z;
                e1->flags |= 0x80;
            }
        }
        break;
    case 3:
    case 4:
        self->acc->d8->p64->m6(-1, 0x20000000);
        break;
    case 6:
    case 7:
        fn_27_89544(self->acc->d8->p7c, 3);
        break;
    }
}
