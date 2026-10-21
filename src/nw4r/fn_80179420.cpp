#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_80179420(Vec3* dst, const Vec3* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
