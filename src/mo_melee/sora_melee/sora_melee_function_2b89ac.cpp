#include <types.h>
#include <it/item.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_types.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

union Pair { struct { float x, y; }; u32 bits[2]; u64 raw; };
struct V2 { float x, y; };
struct V3 { float x, y, z; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual u64 slot2();
    virtual int slot3();
    virtual Vec3f slot4();
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual Vec3f slot14(int);
    virtual void slot15(V3*, int);
    virtual void slot16();
    virtual int slot17(int);
    virtual void slot18(int);
};

struct Class_1E0A8_base { char pad[0xf8]; };
class Class_1E0A8 : public Class_1E0A8_base {
public:
    virtual void fn_27_E6C88();
    virtual void fn_27_E640C();
    virtual u64 fn_27_E641C();
    virtual void fn_27_CCA6C();
    virtual void fn_27_CCA8C();
    virtual void fn_27_CC984();
    virtual void fn_27_E65A8();
};

struct Pad8 { int a, b; };
#define VT_FILL virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
class VtB : public Pad8 {
public:
    VT_FILL
    virtual u64 s57(int, int);
};

struct Data {
    char p0[12];
    Object_vptr_0* oc;
    VtB* p10;
    Object_vptr_0* p14;
    char p1[0x4c];
    Object_vptr_0* p64;
};
struct Access {
    char p0[8];
    BaseItem* item;
    char p1[0xcc];
    Data* d8;
};

struct Self {
    char p0[0x40];
    Object_vptr_0 o40;
    char p1[4];
    V3 vel;
    char p2[0x18];
    V3 scl;
    char p3[0x14];
    Object_vptr_0 a;
    char pa;
    unsigned char aflag : 1;
    char p4[2];
    V2 v94;
    char p5[0x3c];
    Object_vptr_0 b;
    char pb;
    unsigned char bflag : 1;
    char p6[2];
    float e0;
    char p7[0x14];
    Object_vptr_0 c;
    char pc;
    unsigned char cflag : 1;
    char p8[2];
    V2 v100;
    V2 v108;
    V2 v110;
    V2 v118;
    V2 v120;
    char p9[0x200 - 0x128];
    Object_vptr_0 d;
    char pd;
    unsigned char dflag : 1;
    char p10[2];
    V2 v208;
    char p11[0x2c0 - 0x210];
    u32 cur;
    u32 prev;
    int p12;
    int state;
    char p13[0x2f8 - 0x2d0];
    V3 pos;
};

extern "C" {
extern const float lbl_27_rodata_5EB8[];
int fn_27_2B823C(Self*, Access*, Pair*, int, int);
void fn_27_28880C(BaseItem*, int);
float fn_8003DDD0(Pair*, Pair*, float, float, float);
void fn_8003E05C(Vec3f*, V3*, V3*, float);
float rsqrtf__Ff(float);
}

static inline Pair addPair(const Pair& l, const Pair& r) {
    Pair o;
    o.x = l.x + r.x;
    o.y = l.y + r.y;
    return o;
}

static inline void combinePair(Pair& out, const Pair& l, const Pair& r) {
    Pair sum;
    sum.x = l.x + r.x;
    sum.y = l.y + r.y;
    out.bits[0] = sum.bits[0];
    out.bits[1] = sum.bits[1];
}

static inline void reverseVelocity(Self* self, float neg) {
    Vec3f tv = self->o40.slot4();
    V3 sc;
    LocalScale((const Vec*)&tv, (Vec*)&sc, neg);
    self->vel.x = sc.x;
    self->vel.y = sc.y;
    self->vel.z = sc.z;
}

static inline float getVelocityLength(Self* self, const float* k) {
    Vec3f v = self->o40.slot4();
    float l2 = v.m_z * v.m_z + (v.m_x * v.m_x + v.m_y * v.m_y);
    float length;
    if ((float)(double)nw4r::math::FAbs(l2) <= k[10]) length = k[1];
    else length = l2 * rsqrtf__Ff(l2);
    return length;
}

extern "C" void fn_27_2B89AC(Self* self, Access* access) {
    Pair v2, result, cur;
    V2 t8, tp;
    Pair qC8, pC0, sumB8, aB0, bA8, vA0, v98;
    V2 t90, t88, t80, t78;
    Vec2f vertical;
    V2 t68;
    Pair q60, t58, t50, t48;
    V2 t4, t3;
    Pair combined, t2, t1;
    V2 z;
    const float* k = lbl_27_rodata_5EB8;
    BaseItem* item = access->item;
    Object_vptr_0* ctrl = access->d8->oc;
    Object_vptr_0* work = access->d8->p64;
    int moved = 0;
    int r31 = work->slot17(0x12000004);
    float f31 = k[1];
    int r25 = (self->cur >> 3) & 1;
    v2.x = k[1];
    v2.y = k[2];
    if (r25) {
        qC8.raw = access->d8->p10->s57(8, 0);
        v2.y = qC8.y;
        v2.x = qC8.x;
        float zero = k[1];
        pC0.x = zero;
        pC0.y = k[2];
        f31 = k[14] * fn_8003DDD0(&pC0, &v2, zero, qC8.y, qC8.x);
    }
    if (self->cur != self->prev) {
        int param = item->getParam((itValueAccesser::ParamInt)0x5b6c);
        if (self->cur) {
            if (self->state != 3 && (param & 13)) {
                bA8.raw = self->b.slot2();
                aB0.raw = self->a.slot2();
                sumB8 = addPair(aB0, bA8);
                result.bits[0] = sumB8.bits[0];
                result.bits[1] = sumB8.bits[1];
                if (self->dflag) {
                    vA0.raw = self->d.slot2();
                    result.x += vA0.x;
                    result.y += vA0.y;
                }
                if (self->cflag) {
                    v98.raw = self->c.slot2();
                    result.x += v98.x;
                    result.y += v98.y;
                }
                int ret = fn_27_2B823C(self, access, &result, param, 1);
                if (ret) {
                    if (access->d8->p14->slot3() == 0) {
                        float zero = k[1];
                        float x = result.x;
                        t90.x = x;
                        t90.y = zero;
                        self->v100 = t90;
                        result.x = zero;
                    } else if (self->cflag) {
                        self->c.slot6();
                    }
                    if (self->dflag) {
                        t88.x = result.x;
                        t88.y = k[1];
                        self->v208 = t88;
                        t80.x = k[1];
                        t80.y = k[1];
                        self->v94 = t80;
                    } else {
                        t78.x = result.x;
                        t78.y = k[1];
                        self->v94 = t78;
                    }
                    if (self->bflag) {
                        vertical.m_y = result.y;
                        vertical.m_x = k[1];
                        self->e0 = vertical.m_y;
                    } else {
                        t68.y = result.y;
                        t68.x = k[1];
                        self->v94 = t68;
                    }
                    float sq = result.x * result.x + result.y * result.y;
                    float len;
                    if ((float)(double)nw4r::math::FAbs(sq) <= k[10]) len = k[1];
                    else len = sq * rsqrtf__Ff(sq);
                    if (len > k[11] && (!(ret & 1) || result.y > k[1])) {
                        if (ret & 4) {
                            reverseVelocity(self, k[0]);
                        }
                        work->slot5(ret, 0x10000004);
                        fn_27_28880C(item, 3);
                    }
                }
                if (r31) moved = 1;
            }
            float f2 = getVelocityLength(self, k);
            float t0 = k[37] + k[31] * f2;
            V3 ts170;
            ts170.x = t0;
            ts170.y = t0;
            ts170.z = t0;
            self->scl = ts170;
        } else {
            V3 ts164;
            ts164.x = k[1];
            ts164.y = k[1];
            ts164.z = k[3];
            self->scl = ts164;
        }
    }
    q60.raw = self->c.slot2();
    cur.bits[0] = q60.bits[0];
    cur.bits[1] = q60.bits[1];
    float f30 = cur.x;
    if (self->aflag) {
        t58.raw = self->a.slot2();
        f30 += t58.x;
    }
    if (self->dflag) {
        t50.raw = self->d.slot2();
        f30 += t50.x;
    }
    if (self->cflag) {
        t48.raw = self->c.slot2();
        f30 += t48.x;
    }
    if (r25) {
        if (f31 > k[36]) moved = 1;
        else if (r31 && (float)(double)nw4r::math::FAbs(f30) > k[38]) moved = 1;
    }
    if (r31) moved = 1;
    if (r25) {
        float ft = v2.x * item->getParam((itValueAccesser::ParamFloat)0xd60);
        t8.x = ft;
        t8.y = k[1];
        if (self->cur & 2) {
            if (cur.x < k[1]) cur.x = k[1];
            if (f30 < k[1]) f30 = k[1];
        } else if (self->cur & 4) {
            if (cur.x > k[1]) cur.x = k[1];
            if (f30 > k[1]) f30 = k[1];
        }
        float p1 = item->getParam((itValueAccesser::ParamFloat)0xd61);
        tp.x = p1;
        tp.y = p1;
        self->cflag = 1;
        self->v108 = t8;
        float p3 = item->getParam((itValueAccesser::ParamFloat)0xd6d);
        t4.x = p3;
        t4.y = k[2];
        self->v120 = t4;
        t3.x = k[1];
        t3.y = k[1];
        self->v110 = t3;
        self->v118 = tp;
        self->v100.x = cur.x;
        self->v100.y = cur.y;
    } else if (self->cflag) {
        t1.raw = self->c.slot2();
        t2.raw = self->a.slot2();
        combinePair(combined, t2, t1);
        self->v94.x = combined.x;
        self->v94.y = combined.y;
        self->c.slot6();
        z.x = k[1];
        z.y = k[1];
        self->v108 = z;
        self->cflag = 0;
    }
    if (moved) {
        access->d8->p64->slot18(0x12000004);
        Vec3f t14 = ctrl->slot14(0);
        V3 pos = self->pos;
        pos.z = pos.z + t14.m_z;
        V3 vec140;
        vec140.x = k[1];
        vec140.y = k[1];
        vec140.z = k[1];
        fn_8003E05C(&t14, &pos, &vec140, k[38]);
        vec140.z = vec140.z - k[19] * f30;
        ctrl->slot15(&vec140, 0);
    } else {
        Vec3f t134 = ctrl->slot14(0);
        V3 vec128;
        float zero = k[1];
        float oldZ = t134.m_z;
        vec128.x = zero;
        vec128.y = zero;
        vec128.z = oldZ;
        if (self->state == 1 || self->state == 5) vec128.z = f31;
        else vec128.z = k[1];
        V3 w;
        w.x = k[1];
        w.y = k[1];
        w.z = k[1];
        fn_8003E05C(&t134, &vec128, &w, k[39]);
        ctrl->slot15(&w, 0);
    }
}
