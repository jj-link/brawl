#pragma force_active on
#pragma fp_contract off
#include <math.h>
#include <nw4r/math/math_arithmetic.h>

class VT {
public:
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long long slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual float slot16();
    virtual void slot17();
    virtual float slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    char pad4[4];
    float f8;
    float fC;
};

struct Base8 { char pad[8]; };
class VT8 : public Base8 {
public:
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
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
};

struct Mods {
    char pad0[0x38];
    VT8* p38;
    char pad3C[0x20];
    VT* p5C;
    char pad60[0x1C];
    VT* p7C;
};

struct Access {
    char pad[0xd8];
    Mods* mods;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

inline void crossV(Vec3* o, const Vec3* p, const Vec3* q) {
    o->x = p->y * q->z - p->z * q->y;
    o->y = p->z * q->x - p->x * q->z;
    o->z = p->x * q->y - p->y * q->x;
}

inline float absAngle(float y, float x) {
    return atan2f((float)(double)nw4r::math::FAbs(y), (float)(double)nw4r::math::FAbs(x));
}

union Pair {
    unsigned long long raw;
    struct {
        float hi;
        float lo;
    } v;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float rsqrtf__Ff(float);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_2198[];

void fn_27_16CEC4(void*, Access* self) {
    const float* c = lbl_27_rodata_2198;
    Vec3 v;
    Vec3 cr;
    Vec3 av;
    float res[2];
    Pair pr;
    float a = self->mods->p5C->slot16();
    float b = self->mods->p5C->slot18();
    if (c[3] != a || c[3] != b) {
        void* q = self->mods->p7C->slot6(4);
        if ((((unsigned char*)q)[5] >> 7) & 1) {
            VT* e = (VT*)__dynamic_cast(q, 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
            pr.raw = e->slot2();
            v.x = pr.v.hi;
            v.y = pr.v.lo;
            v.z = c[3];
            float sq = v.z * v.z + (v.x * v.x + v.y * v.y);
            float len;
            if ((float)(double)nw4r::math::FAbs(sq) <= c[4]) {
                len = c[3];
            } else {
                len = sq * rsqrtf__Ff(sq);
            }
            if (!(len < c[6])) {
                self->mods->p38->slot32();
                float ang = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(self, 0xCDA, 0);
                if (absAngle(v.y, v.x) > ang) {
                    float t = atan2f(v.y, v.x);
                    float d = (float)(double)nw4r::math::FAbs((v.y * a) + ((-v.x) * b));
                    av.x = a;
                    av.y = b;
                    av.z = c[3];
                    crossV(&cr, &v, &av);
                    float k = d / len;
                    if (cr.z < c[3]) {
                        k = -k;
                    }
                    float ang2 = t + ang * k;
                    float sv = len * sinf(ang2);
                    float cv = len * cosf(ang2);
                    res[1] = sv;
                    res[0] = cv;
                    e->f8 = res[0];
                    e->fC = res[1];
                }
            }
        }
    }
}
}
