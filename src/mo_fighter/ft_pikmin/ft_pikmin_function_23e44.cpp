#pragma force_active on
extern "C" double __fabs(double);
extern "C" float rsqrtf__Ff(float);
extern "C" {
extern const float lbl_113_rodata_E8;
extern const float lbl_113_rodata_EC;
}
struct Vec2 {
    float x, y;
};
struct Holder { Vec2 v; };
inline float length(const Holder& copy) {
    float sum = copy.v.x * copy.v.x + copy.v.y * copy.v.y;
    double d = __fabs((double)sum);
    float mag = (float)d;
    if (mag <= lbl_113_rodata_EC)
        return lbl_113_rodata_E8;
    return sum * rsqrtf__Ff(sum);
}
inline Holder mk(const Vec2* a, const Vec2* b) {
    Vec2 v;
    v.x = b->x - a->x;
    v.y = b->y - a->y;
    Holder h = { v };
    return h;
}
extern "C" float fn_113_23E44(Vec2* a, Vec2* b, int mode) {
    float result = lbl_113_rodata_E8;
    switch (mode) {
    case 0: { double d = __fabs((double)(b->x - a->x)); result = (float)d; break; }
    case 1: result = a->y - b->y; break;
    case 2: result = b->y - a->y; break;
    case 3: {
        Holder copy = mk(a, b);
        result = length(copy);
        break;
    }
    }
    return result;
}
