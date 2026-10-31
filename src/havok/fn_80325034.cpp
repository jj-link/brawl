#pragma force_active on
#pragma fp_contract on

extern float lbl_805A47C8;

struct V4 {
    float x;
    float y;
    float z;
    float w;
} __attribute__((aligned(16)));

static inline float dot3(const V4& a, const V4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

extern "C" int fn_80325034(const V4* a, const V4* b, const V4* c, V4* result) {
    V4 d;
    V4 e;

    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    d.w = a->w - b->w;

    e.x = c->x - b->x;
    e.y = c->y - b->y;
    e.z = c->z - b->z;
    e.w = c->w - b->w;

    float p = dot3(e, d);
    float l = dot3(e, e);

    if (p <= lbl_805A47C8) {
        result->x = b->x;
        result->y = b->y;
        result->z = b->z;
        result->w = b->w;
        return 8;
    }

    if (p >= l) {
        result->x = b->x + e.x;
        result->y = b->y + e.y;
        result->z = b->z + e.z;
        result->w = b->w + e.w;
        return 4;
    }

    p /= l;
    result->x = p * e.x + b->x;
    result->y = p * e.y + b->y;
    result->z = p * e.z + b->z;
    result->w = p * e.w + b->w;
    return 0;
}
