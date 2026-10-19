#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_40_D08(Vec3* dst, const Vec3* src) {
    *dst = *src;
}
