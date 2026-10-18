#pragma force_active on
struct Vec3 {
    float x, y, z;
};

extern "C" bool fn_27_314(const Vec3* a, const Vec3* b,
                          const Vec3* c, const Vec3* d, float margin) {
    if (a->x > b->x) {
        float t = a->x + margin;
        if (t < c->x && t < d->x)
            return false;
        t = b->x - margin;
        if (t > c->x && t > d->x)
            return false;
    } else {
        float t = a->x - margin;
        if (t > c->x && t > d->x)
            return false;
        t = b->x + margin;
        if (t < c->x && t < d->x)
            return false;
    }

    if (a->y > b->y) {
        float t = a->y + margin;
        if (t < c->y && t < d->y)
            return false;
        t = b->y - margin;
        if (t > c->y && t > d->y)
            return false;
    } else {
        float t = a->y - margin;
        if (t > c->y && t > d->y)
            return false;
        t = b->y + margin;
        if (t < c->y && t < d->y)
            return false;
    }

    if (a->z > b->z) {
        float t = a->z + margin;
        if (t < c->z && t < d->z)
            return false;
        t = b->z - margin;
        if (t > c->z && t > d->z)
            return false;
    } else {
        float t = a->z - margin;
        if (t > c->z && t > d->z)
            return false;
        t = b->z + margin;
        if (t < c->z && t < d->z)
            return false;
    }

    return true;
}
