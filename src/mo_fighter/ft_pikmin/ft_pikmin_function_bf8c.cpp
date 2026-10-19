#pragma force_active on
typedef struct Vec2 {
    float x;
    float y;
} Vec2;

extern "C" void fn_113_BF8C(const Vec2 *a, const Vec2 *b, Vec2 *out)
{
    out->x = a->x + b->x;
    out->y = a->y + b->y;
}
