#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

extern "C" void fn_117_D134(Vec2f* dst, const Vec2f* src) {
    dst->x = src->x;
    dst->y = src->y;
}
