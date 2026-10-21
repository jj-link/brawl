#pragma force_active on
struct Vec4 {
    float x, y, z, w;
};

extern "C" void fn_80294740(Vec4* dst, const Vec4* src) {
    *dst = *src;
}
