#pragma force_active on
struct Vec2F {
    float x;
    float y;
};

extern "C" void fn_106_954C(Vec2F* dst, const Vec2F* src) {
    dst->x = src->x;
    dst->y = src->y;
}
