#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

extern "C" void fn_97_D7C0(Vec2* dst, const Vec2* src)
{
    dst->x = src->x;
    dst->y = src->y;
}
