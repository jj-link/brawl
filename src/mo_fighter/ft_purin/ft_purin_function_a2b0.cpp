#pragma force_active on
typedef struct Vec2f {
    float x;
    float y;
} Vec2f;

extern "C" void fn_124_A2B0(Vec2f* dst, const Vec2f* src)
{
    dst->x = src->x;
    dst->y = src->y;
}
