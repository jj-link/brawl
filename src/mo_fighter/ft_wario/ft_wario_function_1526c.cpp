#pragma force_active on
extern "C" {
float rsqrtf__Ff(float);
extern const float lbl_110_rodata_98;
extern const float lbl_110_rodata_A8;

struct Vec2f {
    float x;
    float y;
};

float fn_110_1526C(Vec2f* v) {
    float sq = v->x * v->x + v->y * v->y;
    double d = __fabs((double)sq);
    float a = (float)d;
    if (a <= lbl_110_rodata_A8) {
        return lbl_110_rodata_98;
    }
    return sq * rsqrtf__Ff(sq);
}
}
