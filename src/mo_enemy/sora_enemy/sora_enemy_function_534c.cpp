#pragma force_active on
typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern "C" void fn_41_534C(Vec3f* dst, const Vec3f* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
