#pragma force_active on
struct Vector2f
{
    float x;
    float y;
};

extern "C" Vector2f fn_96_28E4C(const Vector2f* vector, float scale)
{
    Vector2f result;
    result.x = vector->x * scale;
    result.y = vector->y * scale;
    return result;
}
