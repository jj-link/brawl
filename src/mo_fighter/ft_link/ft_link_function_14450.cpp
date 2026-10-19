#pragma force_active on
struct Vector2f
{
    float x;
    float y;
};

extern "C" Vector2f fn_93_14450(const Vector2f* vector, float scale)
{
    Vector2f result;
    result.x = vector->x * scale;
    result.y = vector->y * scale;
    return result;
}
