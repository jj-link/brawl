#pragma force_active on
struct Vec4f {
    float x;
    float y;
    float z;
    float w;
};

extern "C" void fn_80294D1C(Vec4f* v, float s) {
    v->x = v->x * s;
    v->y = v->y * s;
    v->z = v->z * s;
    v->w = v->w * s;
}
