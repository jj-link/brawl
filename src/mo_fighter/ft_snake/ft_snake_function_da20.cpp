#include <math.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/so_module_accesser.h>
#pragma force_active on

float rsqrtf(float);

class Object_vptr_0 {
public:
    virtual void fn_122_ABB4();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(Vec3f* out);
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
    virtual int slot16();
};

struct ObjB {
    char pad0[0x0C];
    Object_vptr_0* c;
    char pad1[0x70 - 0x10];
    Object_vptr_0* z;
};

struct ObjA {
    char pad0[0xD8];
    ObjB* b;
};

struct ObjQ {
    char pad0[0x20];
    float threshold;
};

struct ObjP {
    char pad0[0x7C];
    ObjQ* q;
};

struct Self {
    char pad0[0x60];
    ObjA* a;
    char pad1[0x2D03C - 0x64];
    ObjP* p;
};

extern const float lbl_122_rodata_18;
extern const float lbl_122_rodata_C;

extern "C" {
int fn_122_DA20(Self* self, const Vec3f* b) {
    if (self->a->b->z->slot16() != 0) {
        if (self->a->b->z->slot16() != 0x12E) {
            return 0;
        }
    }

    Vec3f diff;
    Vec3f vec = ((soModuleAccesser*)self->a)->getPostureModule().getPos();

    Vec3fSub(&diff, b, &vec);

    float sum = diff.m_z * diff.m_z + (diff.m_x * diff.m_x + diff.m_y * diff.m_y);
    float a = (float)(double)nw4r::math::FAbs(sum);
    float len;
    if (a <= lbl_122_rodata_18) {
        len = lbl_122_rodata_C;
    } else {
        len = sum * rsqrtf(sum);
    }

    if (len > self->p->q->threshold) {
        return 0;
    }
    return 1;
}
}
