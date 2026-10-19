#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" void fn_125_A220(Vec3f* dst, const Vec3f* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
