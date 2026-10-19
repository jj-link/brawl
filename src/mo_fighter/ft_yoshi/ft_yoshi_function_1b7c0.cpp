#pragma force_active on
extern "C" struct Vector2 {
    float x;
    float y;
};

extern "C" Vector2 fn_95_1B7C0(const Vector2* vector, float scale) {
    Vector2 result;
    result.x = vector->x * scale;
    result.y = vector->y * scale;
    return result;
}
