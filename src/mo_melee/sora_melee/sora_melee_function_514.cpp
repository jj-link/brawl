#pragma force_active on
struct Vec3 {
    float x, y, z;
};

extern "C" int fn_27_514(const Vec3* a, const Vec3* b,
                         const Vec3* c, const Vec3* d, const Vec3* margin) {
    if (a->x > b->x) {
        float t = a->x + margin->x;
        if (t < c->x && t < d->x)
            return 0;
        t = b->x - margin->x;
        if (t > c->x && t > d->x)
            return 0;
    } else {
        float t = a->x - margin->x;
        if (t > c->x && t > d->x)
            return 0;
        t = b->x + margin->x;
        if (t < c->x && t < d->x)
            return 0;
    }

    if (a->y > b->y) {
        float t = a->y + margin->y;
        if (t < c->y && t < d->y)
            return 0;
        t = b->y - margin->y;
        if (t > c->y && t > d->y)
            return 0;
    } else {
        float t = a->y - margin->y;
        if (t > c->y && t > d->y)
            return 0;
        t = b->y + margin->y;
        if (t < c->y && t < d->y)
            return 0;
    }

    if (a->z > b->z) {
        float t = a->z + margin->z;
        if (t < c->z && t < d->z)
            return 0;
        t = b->z - margin->z;
        if (t > c->z && t > d->z)
            return 0;
    } else {
        float t = a->z - margin->z;
        if (t > c->z && t > d->z)
            return 0;
        t = b->z + margin->z;
        if (t < c->z && t < d->z)
            return 0;
    }

    return 1;
}