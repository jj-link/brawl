#pragma force_active on
extern "C" float fn_27_896EC(float a, float b, float c, float d);

struct Vec2Work {
    float x;
    float y;
};

extern "C" {
Vec2Work fn_27_895B8(const Vec2Work* a, const Vec2Work* b, const Vec2Work* c, const Vec2Work* d) {
    Vec2Work r = *a;
    r.x = fn_27_896EC(a->x, b->x, c->x, d->x);
    r.y = fn_27_896EC(a->y, b->y, c->y, d->y);
    return r;
}
}
