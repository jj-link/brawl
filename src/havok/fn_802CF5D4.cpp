#pragma force_active on
#pragma fp_contract on
extern float lbl_805A4068;
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));

static inline float dot3(const V4& a, const V4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

extern "C" void fn_802CF5D4(const V4* a, const V4* b, const V4* c, V4* out) {
    V4 d, e;
    d.x = b->x - a->x; d.y = b->y - a->y; d.z = b->z - a->z; d.w = b->w - a->w;
    e.x = c->x - b->x; e.y = c->y - b->y; e.z = c->z - b->z; e.w = c->w - b->w;
    float p = dot3(e, d);
    p = -p;
    float l = dot3(e, e);
    if (p <= lbl_805A4068) {
        out->x = b->x; out->y = b->y; out->z = b->z; out->w = b->w;
    } else if (p >= l) {
        out->x = c->x; out->y = c->y; out->z = c->z; out->w = c->w;
    } else {
        p /= l;
        out->x = p * e.x + b->x; out->y = p * e.y + b->y;
        out->z = p * e.z + b->z; out->w = p * e.w + b->w;
    }
}