#pragma force_active on
extern "C" {
float rsqrtf__Ff(float);
extern const float lbl_94_rodata_BC;
extern const float lbl_94_rodata_A8;

struct Vec2f {
    float x;
    float y;
};

float fn_94_20200(Vec2f* v) {
    float s = v->x * v->x + v->y * v->y;
    if ((float)__fabs((double)s) <= lbl_94_rodata_BC) {
        return lbl_94_rodata_A8;
    }
    return s * rsqrtf__Ff(s);
}
}
