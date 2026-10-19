#pragma force_active on
struct Vec3f {
    float x, y, z;
};

extern "C" void fn_122_D564(Vec3f* dst, const Vec3f* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
