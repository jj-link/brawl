#pragma force_active on
struct Vec2 {
    float x;
    float y;
};

extern "C" Vec2 fn_110_152E0(const Vec2* vector, float scale) {
    Vec2 result;
    result.x = vector->x * scale;
    result.y = vector->y * scale;
    return result;
}
