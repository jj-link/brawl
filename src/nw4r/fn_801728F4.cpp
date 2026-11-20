#include <nw4r/math/math_types.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void fn_801ED008(const Vec3f*, Vec3f*);
void fn_8016FC34(int, Vec3f*, void*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
unsigned short fn_80170150(int, int, void*, float);
extern const float lbl_805A2F28;
extern const float lbl_805A2F2C;
extern const float lbl_805A2F30;
extern const float lbl_805A2F34;
extern const float lbl_805A2F38;
extern const float lbl_805A2F3C;
}

struct TgtBase { char pad[0x1c]; };
struct Tgt : TgtBase {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(unsigned short, Vec3f, Vec3f, int, void*, int, int, float);
};
struct Ctx { char pad[0x67]; signed char c67; char pad2[0xe8 - 0x68]; unsigned short e8; char pad3[2]; unsigned int rnd; int f0; int f4; int f8; char fc[4]; };
struct I3 { unsigned a, b, c; };

static inline float rnd01(Ctx* c) {
    c->rnd = c->rnd * 0x343FD + 0x269EC3;
    return (float)(c->rnd >> 16) / lbl_805A2F30;
}

static inline float rnd(Ctx* c) {
    return rnd01(c) * lbl_805A2F34 - lbl_805A2F38;
}

static inline void cp(Vec3f* d, Vec3f* s) {
    __memcpy(d, s, 12);
}

extern "C" void fn_801728F4(int a0, Vec3f* p1, Vec3f* p2, Ctx* ctx, Tgt* own, int a5, int a6, float f) {
    Vec3f v, w, o;
    if (lbl_805A2F28 != p2->m_x || lbl_805A2F28 != p2->m_y || lbl_805A2F28 != p2->m_z)
        fn_801ED008(p2, p2);
    cp(&v, p1);
    if (nw4r::math::VEC3LenSq((const nw4r::math::VEC3*)&v) <= lbl_805A2F2C) {
        v.m_x = rnd(ctx);
        v.m_y = rnd(ctx);
        v.m_z = rnd(ctx);
    }
    if (lbl_805A2F28 != v.m_x || lbl_805A2F28 != v.m_y || lbl_805A2F28 != v.m_z)
        fn_801ED008(&v, &v);
    cp(&w, p1);
    w.m_y = lbl_805A2F28;
    if (nw4r::math::VEC3LenSq((const nw4r::math::VEC3*)&w) <= lbl_805A2F2C) {
        w.m_x = rnd(ctx);
        w.m_z = rnd(ctx);
    }
    if (lbl_805A2F28 != w.m_x || lbl_805A2F28 != w.m_y || lbl_805A2F28 != w.m_z)
        fn_801ED008(&w, &w);
    fn_8016FC34(a0, &o, ctx, p1, p2, &v, &w);
    own->v3(fn_80170150(a0, a5, ctx, f), *p1, o, a6, ctx->fc, ctx->f8, ctx->e8,
            lbl_805A2F3C * (float)ctx->c67 * rnd01(ctx) + lbl_805A2F38);
}
