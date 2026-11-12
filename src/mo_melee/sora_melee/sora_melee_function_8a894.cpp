#include <types.h>
#include <revolution/MTX.h>

static void L_PSVECAdd(const Vec* a, const Vec* b, Vec* sum);
static inline void L_PSVECScale(const Vec* in, Vec* out, f32 scale);
static void L_PSVECNormalize(const Vec* in, Vec* out);
static f32 L_PSVECMag(const Vec* v);
static f32 L_PSVECDotProduct(const Vec* a, const Vec* b);
static void L_PSVECCrossProduct(const Vec* a, const Vec* b, Vec* prod);
static void L_C_VECHalfAngle(const Vec* a, const Vec* b, Vec* half);
static f32 L_PSVECSquareDistance(const Vec* a, const Vec* b);

#define PSVECAdd L_PSVECAdd
#define PSVECScale L_PSVECScale
#define PSVECNormalize L_PSVECNormalize
#define PSVECMag L_PSVECMag
#define PSVECDotProduct L_PSVECDotProduct
#define PSVECCrossProduct L_PSVECCrossProduct
#define C_VECHalfAngle L_C_VECHalfAngle
#define PSVECSquareDistance L_PSVECSquareDistance
#include <../src/revolution/MTX/vec.c>
#undef PSVECAdd
#undef PSVECScale
#undef PSVECNormalize
#undef PSVECMag
#undef PSVECDotProduct
#undef PSVECCrossProduct
#undef C_VECHalfAngle
#undef PSVECSquareDistance

#include <mt/mt_vector.h>
#include <orch_helpers.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_BC8;

struct Obj {
    unsigned char pad[8];
    Vec3f v;
};

static inline void scaleW(const Vec* in, Vec* out, f32 s) {
    L_PSVECScale(in, out, s);
}

static inline void reflect(Obj* self, const Vec3f* dir) {
    Vec3f out;
    Vec b;
    Vec a;
    float two = lbl_27_rodata_BC8;
    scaleW((const Vec*)dir, &a, two);
    float dot = dir->m_x * self->v.m_x +
                dir->m_y * self->v.m_y +
                dir->m_z * self->v.m_z;
    scaleW(&a, &b, dot);
    Vec3fSub_v905145(&out, &self->v, (const Vec3f*)&b);
    self->v = out;
}

extern "C" void fn_27_8A894(Obj* self, const Vec3f* dir) {
    reflect(self, dir);
}
