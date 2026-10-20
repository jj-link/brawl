#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" float fn_27_E58(Vec3f* v) {
    return v->x * v->x + v->y * v->y + v->z * v->z;
}
