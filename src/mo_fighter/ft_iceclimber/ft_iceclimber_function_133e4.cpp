#pragma force_active on
typedef struct Vec2 {
    float x;
    float y;
} Vec2;

extern "C" void fn_105_133E4(Vec2* dst, const Vec2* src)
{
    dst->x = src->x;
    dst->y = src->y;
}
