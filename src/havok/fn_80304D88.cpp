#pragma force_active on
struct Vec3 {
    float x, y, z;
};

extern "C" void fn_80304D88(Vec3* out, const Vec3* a, const Vec3* b, const Vec3* margin) {
    float t;
    if (b->x > margin->x) {
        t = a->x;
    } else {
        t = out->x;
    }
    out->x = t;
    if (b->y > margin->x) {
        t = a->x;
    } else {
        t = out->y;
    }
    out->y = t;
    if (b->z > margin->x) {
        t = a->x;
    } else {
        t = out->z;
    }
    out->z = t;
}