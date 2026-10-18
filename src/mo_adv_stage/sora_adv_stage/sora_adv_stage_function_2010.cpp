#pragma force_active on
typedef struct Vec2f {
    float x;
    float y;
} Vec2f;

extern "C" void fn_40_2010(Vec2f *dst, const Vec2f *src)
{
    dst->x = src->x;
    dst->y = src->y;
}
