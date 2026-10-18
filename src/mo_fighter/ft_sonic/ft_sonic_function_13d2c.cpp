#pragma force_active on
typedef struct {
    float x;
    float y;
} Vec2f;

extern "C" void fn_123_13D2C(float *dst, const Vec2f *src, float z) {
    dst[0] = src->x;
    dst[1] = src->y;
    dst[2] = z;
}
