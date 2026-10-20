#pragma force_active on
typedef struct {
    float x;
    float y;
    float z;
} Vec3f;

extern "C" void fn_27_275FEC(Vec3f* dst, const Vec3f* src) {
    *dst = *src;
}
