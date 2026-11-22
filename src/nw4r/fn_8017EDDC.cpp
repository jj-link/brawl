#include <nw4r/math/math_types.h>
#include <revolution/GX/GXVert.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_805A3074;
extern float lbl_805A3078;
extern const float lbl_805A3090;
extern const float lbl_805A3094;

struct Vertex {
    nw4r::math::VEC3 p;
    nw4r::math::VEC3 n;
    float t;
};

inline Vertex Interpolate(const Vertex* a, const Vertex* b, const Vertex* c,
                          const nw4r::math::VEC3& weights) {
    Vertex out;
    out.p = (a->p * weights.x + b->p * weights.y) + c->p * weights.z;
    out.n = (a->n * weights.x + b->n * weights.y) + c->n * weights.z;
    out.t = c->t * weights.z + (a->t * weights.x + b->t * weights.y);
    return out;
}

void fn_8017EDDC(void*, const Vertex* a, const Vertex* b, const Vertex* c, int flags) {
    using namespace nw4r::math;
    VEC3 weights;
    float t = lbl_805A3078;
    weights.x = lbl_805A3090 + (lbl_805A3090 * t - t);
    float negT = lbl_805A3094 * t;
    weights.y = lbl_805A3090 + (negT + t);
    weights.z = lbl_805A3090 * t;
    Vertex out = Interpolate(a, b, c, weights);
    float tex = out.t;
    GXPosition3f32(out.p.x, out.p.y, out.p.z);
    if (flags & 1) GXTexCoord2f32(lbl_805A3078, tex);
    GXPosition3f32(out.n.x, out.n.y, out.n.z);
    if (flags & 1) GXTexCoord2f32(lbl_805A3074, tex);
}
}
