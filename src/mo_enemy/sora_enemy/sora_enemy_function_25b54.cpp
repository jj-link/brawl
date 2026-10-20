#pragma force_active on
struct Vec2 {
    float x, y;
};

extern "C" float fn_41_25A50(void*, void*, Vec2, Vec2, int);

extern "C" bool fn_41_25B54(
    void* a, void* b, Vec2 c, Vec2 d, int e, float limit)
{
    float value = fn_41_25A50(a, b, c, d, e);
    float bound = (float)__fabs(limit);
    float magnitude = (float)__fabs(value);
    return magnitude <= bound;
}
